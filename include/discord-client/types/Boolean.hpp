#ifndef LBVR_TYPES_BOOLEAN_HPP
#define LBVR_TYPES_BOOLEAN_HPP

#include "__DiscordParam.hpp"

namespace lbvr {
namespace types {

namespace __internal {
class __BooleanInitializer {
public:
	constexpr operator bool() { return false; }
};
}

class Boolean : public __internal::__DiscordParam<bool> {
public:
	using __internal::__DiscordParam<bool>::__DiscordParam;
	virtual json11::Json toJson(void) const override;
	virtual std::string toString(void) const override;
};

class NullableBoolean : public __internal::__NullableDiscordParam<bool, __internal::__BooleanInitializer> {
public:
	using __internal::__NullableDiscordParam<bool, __internal::__BooleanInitializer>::__NullableDiscordParam;
	virtual json11::Json toJson(void) const override;
	virtual std::string toString(void) const override;
};

}
}

#endif