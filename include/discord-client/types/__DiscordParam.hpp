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
	T & ref(void) const;
private:
	T value_;
};

template <class T, T _DefVal = T()>
class __NullableDiscordParam : public __DiscordParam<T> {
public:
	__NullableDiscordParam(void) noexcept;
	using __DiscordParam::__DiscordParam;
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
inline T & lbvr::types::__internal::__DiscordParam<T>::ref(void) const {
	return this->value_;
}

template<class T, T _DefVal>
inline lbvr::types::__internal::__NullableDiscordParam<T, _DefVal>::__NullableDiscordParam(void) noexcept
	: value_(_DefVal) {}

template<class T, T _DefVal>
inline lbvr::types::__internal::__NullableDiscordParam<T, _DefVal>::~__NullableDiscordParam(void) noexcept
{}

template<class T, T _DefVal>
inline void lbvr::types::__internal::__NullableDiscordParam<T, _DefVal>::set(const T & value)
{ this->is_set_ = true; __DiscordParam::set(value); }

template<class T, T _DefVal>
inline bool lbvr::types::__internal::__NullableDiscordParam<T, _DefVal>::isSet(void) const noexcept
{ return this->is_set_; }

template<class T, T _DefVal>
inline void lbvr::types::__internal::__NullableDiscordParam<T, _DefVal>::setNull(void) noexcept
{ this->is_set_ = false; this->value_ = _DefVal; }

/*
template<class T, T _DefVal>
inline constexpr T lbvr::types::__internal::__NullableDiscordParam<T, _DefVal>::getDefaultValue(void) const
{ return _DefVal; }
*/

#endif