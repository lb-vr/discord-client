#ifndef LBVR_PARAM_HPP
#define LBVR_PARAM_HPP

#include <string>

namespace lbvr {

class ParamBase {
public:
	virtual std::string toString(void) const noexcept = 0;
};

template <class T>
class Param : ParamBase {
public:

	Param(void) = delete;

	/// @brief Constructor.
	/// @param default_value value when unset.
	Param(const T & default_value) noexcept;

	/// @brief Copy constructor.
	/// @param copy source instance.
	Param(const Param<T> & copy) noexcept;
	
	/// @brief Move constructor.
	/// @param move source instance.
	Param(Param<T> && move) noexcept;

	/// @brief Constructor with value.
	/// @param default_value value when unset.
	/// @param value initial value.
	Param(const T & default_value, const T & value) noexcept;

	/// @brief Destructor
	///
	/// Currently, no operation.
	virtual ~Param(void) noexcept;

	/// @brief Copy assignment
	Param<T> & operator=(const Param<T> & param);

	/// @brief Move assignment
	Param<T> & operator=(Param<T> && param);

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

	/// @brief get value.
	/// @return value if value is set, else returns default value.
	const T & get(void) const noexcept;
	
	/// @brief set value.
	/// @param value new value.
	///
	/// After you call this function, isSet() returns true.
	void set(const T & value) noexcept;

	/// @brief cast to T.
	/// @return value if value is set, else returns default value.
	/// @sa get()
	operator T(void) noexcept;

	/// @brief return "Param" string.
	/// @return string "Param"
	virtual std::string toString(void) const noexcept override;

private:
	Param(const T & default_value, const T & value, const bool is_set) noexcept;

	const T default_value_;
	T value_;
	bool is_set_;
};

/////////////////////////////////////////////////////////////////////////////////
// BELOW INLINE IMPLEMENTS
/////////////////////////////////////////////////////////////////////////////////
template<class T>
inline Param<T>::Param(const T & default_value) noexcept
	: Param(default_value, default_value, false) {}

template<class T>
inline Param<T>::Param(const Param<T>& copy) noexcept
	: Param(copy.default_value_, copy.value_, copy.is_set_) {}

template<class T>
inline Param<T>::Param(Param<T>&& move) noexcept
	: Param(std::move(move.default_value_), std::move(move.value_), move.is_set_) {}

template<class T>
inline Param<T>::Param(const T & default_value, const T & value) noexcept
	: Param(default_value, value, true) {}

template<class T>
inline Param<T>::~Param(void) noexcept {}

template<class T>
inline Param<T>& Param<T>::operator=(const Param<T>& param) {
	this->value_ = param.value_;
	this->default_value_ = param.default_value_;
	return *this;
}

template<class T>
inline Param<T>& Param<T>::operator=(Param<T>&& param) {
	if (this != &param) {
		this->value_ = std::move(param.value_);
		this->default_value_ = std::move(param.default_value_);
	}
	return *this;
}

template<class T>
inline void Param<T>::clear(void) noexcept {
	this->value_ = this->default_value_;
	this->is_set_ = false;
}

template<class T>
inline bool Param<T>::isSet(void) noexcept
{ return this->is_set_; }

template<class T>
inline const T & Param<T>::get(void) const noexcept
{ return this->value_; }

template<class T>
inline void Param<T>::set(const T & value) noexcept {
	this->is_set_ = true;
	this->value_ = value;
}

template<class T>
inline Param<T>::operator T(void) noexcept
{ return this->get(); }

template<class T>
inline std::string Param<T>::toString(void) const noexcept
{ return "A Param"; }

template<class T>
inline Param<T>::Param(const T & default_value, const T & value, const bool is_set) noexcept
	: default_value_(default_value), value_(value), is_set_(is_set) {}

}

#endif