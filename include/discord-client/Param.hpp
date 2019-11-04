/*
#ifndef LBVR_PARAM_HPP
#define LBVR_PARAM_HPP

#include <string>
#include <iostream>
#include <cassert>
#include <memory>
#include "json11.hpp"

namespace lbvr {

class ParamBase {
public:
	virtual std::string toString(void) const noexcept = 0;
	virtual json11::Json toJson(void) const noexcept = 0;
};

template <class T>
class Param : public ParamBase {
public:
	/// @brief Constructor with value.
	Param(const T & value) noexcept;

	Param(T && value) noexcept;

	/// @brief Copy constructor.
	Param(const Param & cp) noexcept;

	/// @brief Move constructor.
	Param(Param && mv) noexcept;

	/// @brief Destructor.
	virtual ~Param(void) noexcept;

	/// @brief get value.
	virtual const T & get(void) const noexcept;

	/// @brief set value.
	/// @param value new value.
	virtual void set(const T & value) noexcept;

	/// @brief Copy assignment
	Param<T> & operator=(const Param<T> & param);

	/// @brief Move assignment
	Param<T> & operator=(Param<T> && param);

	/// @brief cast to T.
	/// @return value if value is set, else returns default value.
	/// @sa get()
	operator T(void) noexcept;
protected:
	T & getRef(void) noexcept;
private:
	T value_;
};

template <class T>
class EnumParam : public Param<T> {
public:
	using Param<T>::Param;

	/// @brief getAsInt.
	int getAsInt(void) const noexcept;

	/// @brief toJson.
	virtual json11::Json toJson(void) const noexcept;
};

/////////////////////////////////////////////////////////////////////////////////
// BELOW INLINE IMPLEMENTS
/////////////////////////////////////////////////////////////////////////////////
template<class T>
inline Param<T>::Param(const T & value) noexcept
	: value_(value) {}

template<class T>
inline Param<T>::Param(T && value) noexcept
	: value_(std::move(value)) {}

template<class T>
inline Param<T>::Param(const Param<T>& copy) noexcept
	: value_(copy.value_) {}

template<class T>
inline Param<T>::Param(Param<T>&& move) noexcept
	: value_(std::move(move.value_)) {}

template<class T>
inline Param<T>::~Param(void) noexcept {}

template<class T>
inline Param<T>& Param<T>::operator=(const Param<T>& param) {
	this->value_ = param.value_;
	return *this;
}

template<class T>
inline Param<T>& Param<T>::operator=(Param<T>&& param) {
	if (this != &param) {
		this->value_ = std::move(param.value_);
	}
	return *this;
}

template<class T>
inline const T & Param<T>::get(void) const noexcept { return this->value_; }

template<class T>
inline void Param<T>::set(const T & value) noexcept {
	this->value_ = value;
}

template<class T>
inline Param<T>::operator T(void) noexcept { return this->get(); }

template<class T>
inline T & Param<T>::getRef(void) noexcept { return this->value_; }

template<class T>
inline int EnumParam<T>::getAsInt(void) const noexcept {
	return static_cast<int>(this->get());
}

template<class T>
inline json11::Json EnumParam<T>::toJson(void) const noexcept {
	return json11::Json(this->getAsInt());
}

}

#endif*/