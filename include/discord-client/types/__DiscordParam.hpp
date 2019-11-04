#ifndef LBVR_TYPES_INTERNAL_DISCORDPARAM_HPP
#define LBVR_TYPES_INTERNAL_DISCORDPARAM_HPP

#include "../json11.hpp"
#include <string>

namespace lbvr {
namespace types {
namespace __internal {
class __DiscordParamBase {
public:
	virtual json11::Json toJson(void) const = 0;
	virtual std::string toString(void) const = 0;
};

template <class T>
class __DiscordParam : public __DiscordParamBase {
public:
	__DiscordParam(const T & value) noexcept;
	__DiscordParam(const __DiscordParam & cp) noexcept;
	__DiscordParam(__DiscordParam && mv) noexcept;
	virtual ~__DiscordParam(void) noexcept;

	virtual const T & get(void) const;
	virtual void set(const T & value);
protected:
	T & ref(void);
private:
	T value_;
};

template <class T, class _Initializer = T>
class __NullableDiscordParam : public __DiscordParam<T> {
public:
	__NullableDiscordParam() noexcept;
	__NullableDiscordParam(const T & value) noexcept;
	__NullableDiscordParam(const __NullableDiscordParam<T> & cp);
	__NullableDiscordParam(__NullableDiscordParam<T> && mv);
	virtual ~__NullableDiscordParam(void) noexcept;
	
	virtual void set(const T & value) override;
	bool isSet(void) const noexcept;
	void setNull(void) noexcept;

	//static constexpr T getDefaultValue(void) const;
private:
	bool is_set_;
};

} // end of __internal
} // end of types
} // end of lbvr

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Implements
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
inline lbvr::types::__internal::__DiscordParam<T>::__DiscordParam(const T & value) noexcept
	: value_(value) {}

template<class T>
inline lbvr::types::__internal::__DiscordParam<T>::__DiscordParam(const __DiscordParam & cp) noexcept
	: value_(cp.value_) {}

template<class T>
inline lbvr::types::__internal::__DiscordParam<T>::__DiscordParam(__DiscordParam && mv) noexcept
	: value_(std::move(mv.value_)) {}

template<class T>
inline lbvr::types::__internal::__DiscordParam<T>::~__DiscordParam(void) noexcept
{}

template<class T>
inline const T & lbvr::types::__internal::__DiscordParam<T>::get(void) const
{ return this->value_; }

template<class T>
inline void lbvr::types::__internal::__DiscordParam<T>::set(const T & value)
{ this->value_ = value; }

template<class T>
inline T & lbvr::types::__internal::__DiscordParam<T>::ref(void) {
	return this->value_;
}

template<class T, class _Initializer>
inline lbvr::types::__internal::__NullableDiscordParam<T, _Initializer>::__NullableDiscordParam() noexcept
	: __DiscordParam(_Initializer()), is_set_(false) {}

template<class T, class _Initializer>
inline lbvr::types::__internal::__NullableDiscordParam<T, _Initializer>::__NullableDiscordParam(const T & value) noexcept
	: __DiscordParam(value), is_set_(true) {}

template<class T, class _Initializer>
inline lbvr::types::__internal::__NullableDiscordParam<T, _Initializer>::__NullableDiscordParam(const __NullableDiscordParam<T> & cp)
	: __DiscordParam(cp), is_set_(cp.is_set_) {}

template<class T, class _Initializer>
inline lbvr::types::__internal::__NullableDiscordParam<T, _Initializer>::__NullableDiscordParam(__NullableDiscordParam<T> && mv)
	: __DiscordParam(std::move(mv)), is_set_(mv.is_set_) {}

template<class T, class _Initializer>
inline lbvr::types::__internal::__NullableDiscordParam<T, _Initializer>::~__NullableDiscordParam(void) noexcept
{}

template<class T, class _Initializer>
inline void lbvr::types::__internal::__NullableDiscordParam<T, _Initializer>::set(const T & value)
{ this->is_set_ = true; __DiscordParam::set(value); }

template<class T, class _Initializer>
inline bool lbvr::types::__internal::__NullableDiscordParam<T, _Initializer>::isSet(void) const noexcept
{ return this->is_set_; }

template<class T, class _Initializer>
inline void lbvr::types::__internal::__NullableDiscordParam<T, _Initializer>::setNull(void) noexcept
{ this->is_set_ = false; __DiscordParam::set(_Initializer()); }

#endif