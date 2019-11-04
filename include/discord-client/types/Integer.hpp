#ifndef LBVR_TYPES_INTEGER_HPP
#define LBVR_TYPES_INTEGER_HPP

#include "__DiscordParam.hpp"

namespace lbvr {
namespace types {

namespace __internal {
class __IntegerInitializer {
public:
	constexpr operator int() { return 0; }
};
}

class Integer : public __internal::__DiscordParam<int> {
public:
	using __internal::__DiscordParam<int>::__DiscordParam;
	virtual json11::Json toJson(void) const override;
	virtual std::string toString(void) const override;
};

class NullableInteger : public __internal::__NullableDiscordParam<int, __internal::__IntegerInitializer> {
public:
	using __internal::__NullableDiscordParam<int, __internal::__IntegerInitializer>::__NullableDiscordParam;
	virtual json11::Json toJson(void) const override;
	virtual std::string toString(void) const override;
};

}
}

#endif