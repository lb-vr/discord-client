#ifndef LBVR_TYPES_ENUM_HPP
#define LBVR_TYPES_ENUM_HPP

#include "__DiscordParam.hpp"

namespace lbvr {
namespace types {

namespace __internal {
template <typename T, T _DefVal>
class __EnumInitializer {
	constexpr operator T() { return _DefVal; }
};
}

template <typename T>
class Enum : public __internal::__DiscordParam<T> {
public:
	using __internal::__DiscordParam<T>::__DiscordParam;
	int getAsInt(void) const;
	virtual json11::Json toJson(void) const override;
};

template <typename T, T _DefVal>
class NullableEnum : public __internal::__NullableDiscordParam<T, __internal::__EnumInitializer<T, _DefVal>> {
public:
	using __internal::__NullableDiscordParam<T>::__NullableDiscordParam;
	int getAsInt(void) const;
	virtual json11::Json toJson(void) const override;
};

}
}

template<typename T>
inline int lbvr::types::Enum<T>::getAsInt(void) const {
	return static_cast<int>(this->get());
}

template<typename T>
inline json11::Json lbvr::types::Enum<T>::toJson(void) const {
	return json11::Json(this->getAsInt());
}

template<typename T, T _DefVal>
inline int lbvr::types::NullableEnum<T, _DefVal>::getAsInt(void) const {
	return (this->isSet() ? this->getAsInt() : static_cast<int>(_DefVal));
}

template<typename T, T _DefVal>
inline json11::Json lbvr::types::NullableEnum<T, _DefVal>::toJson(void) const {
	return (this->isSet() ? json11::Json(this->getAsInt()) : json11::Json(nullptr));
}

#endif