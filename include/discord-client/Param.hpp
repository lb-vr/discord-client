#ifndef LBVR_PARAM_HPP
#define LBVR_PARAM_HPP

#include <string>
#include <iostream>
#include <cassert>
#include <memory>

namespace lbvr {

class ParamBase {
public:
	virtual std::string toString(void) const noexcept = 0;
};

template <class T>
class Param : public ParamBase {
public:
	Param(const T & value_) noexcept;
	Param(const Param & cp) noexcept;
	Param(Param && mv) noexcept;
	virtual ~Param(void) noexcept;

	/// @brief get value.
	/// @return value if value is set, else returns default value.
	virtual const T & get(void) const noexcept;

	/// @brief set value.
	/// @param value new value.
	///
	/// After you call this function, isSet() returns true.
	virtual bool set(const T & value) noexcept;

	/// @brief Copy assignment
	Param<T> & operator=(const Param<T> & param);

	/// @brief Move assignment
	Param<T> & operator=(Param<T> && param);

	/// @brief cast to T.
	/// @return value if value is set, else returns default value.
	/// @sa get()
	operator T(void) noexcept;

	virtual bool isValid(const T & try_val) const noexcept;

	/// @brief return "A Param" string.
	/// @return string "A Param"
	virtual std::string toString(void) const noexcept override;
private:
	T value_;
};
/*
template <class T>
class ParamNullable : public Param<std::unique_ptr<T>> {
public:

	ParamNullable(void);

	/// @brief Copy constructor.
	/// @param copy source instance.
	ParamNullable(const ParamNullable<T> & copy) noexcept;
	
	/// @brief Move constructor.
	/// @param move source instance.
	ParamNullable(ParamNullable<T> && move) noexcept;

	/// @brief Destructor
	///
	/// Currently, no operation.
	virtual ~ParamNullable(void) noexcept;

	/// @brief get value.
	/// @return value if value is set, else returns default value.
	virtual const T & get(void) const noexcept override;

	/// @brief set value.
	/// @param value new value.
	///
	/// After you call this function, isSet() returns true.
	virtual bool set(const T & value) noexcept override;

	/// @brief Clear value.
	///
	/// This function unsets value,
	/// isSet() returns false,
	/// get() returns default value.
	void clear(void) noexcept;
	
	/// @brief is value set?
	/// @retval true value is set.
	/// @retval false value is not set. get() returns default value.
	bool isSet(void) noexcept;

	/// @brief return "A Param" or "Null" string.
	/// @return string "A Param" or "Null"
	virtual std::string toString(void) const noexcept override;

};
*/
/////////////////////////////////////////////////////////////////////////////////
// BELOW INLINE IMPLEMENTS
/////////////////////////////////////////////////////////////////////////////////
template<class T>
inline Param<T>::Param(const T & value) noexcept
	: value_(value) {}

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
inline bool Param<T>::set(const T & value) noexcept {
	bool is_valid = this->isValid(value);
	if (is_valid) {
		this->value_ = value;
	}
	else {
		std::cerr << "Tried to set INVALID VALUE. Current value is \"" << this->toString() << "\"." << std::endl;
		assert(this->isValid(value));
	}
	return is_valid;
}

template<class T>
inline Param<T>::operator T(void) noexcept { return this->get(); }

template<class T>
inline bool Param<T>::isValid(const T & try_val) const noexcept { return true; }

template<class T>
inline std::string Param<T>::toString(void) const noexcept { return "A Param"; }
/*
template<class T>
inline ParamNullable<T>::ParamNullable(void)
	: Param(nullptr) {}

template<class T>
inline ParamNullable<T>::ParamNullable(const ParamNullable<T>& copy) noexcept
	: Param(std::make_unique<T>(*copy.get()))
{}

template<class T>
inline ParamNullable<T>::ParamNullable(ParamNullable<T> && move) noexcept
	: Param(std::move(move))
{}

template<class T>
inline ParamNullable<T>::~ParamNullable(void) noexcept {}

template<class T>
inline const T & ParamNullable<T>::get(void) const noexcept {
	assert(this->isSet());
	return *Param::get();
}

template<class T>
inline bool ParamNullable<T>::set(const T & value) noexcept {
	bool is_valid = this->isValid(value);
	if (is_valid) {
		Param::set(std::make_unique<T>(value));
		this->is_set_ = true;
	}
	return is_valid;
}

template<class T>
inline void ParamNullable<T>::clear(void) noexcept {
	Param::get().release();
}

template<class T>
inline bool ParamNullable<T>::isSet(void) noexcept {
	return static_cast<bool>(Param::get());
}

template<class T>
inline std::string ParamNullable<T>::toString(void) const noexcept {
	return (this->isSet() ? "A Param" : "Null");
}
*/
}

#endif