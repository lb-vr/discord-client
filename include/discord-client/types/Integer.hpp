#ifndef LBVR_TYPES_INTEGER_HPP
#define LBVR_TYPES_INTEGER_HPP

#include "__DiscordParam.hpp"

namespace lbvr {
namespace types {

class Integer : public __internal::__DiscordParam<int> {
	virtual json11::Json toJson(void) const override;
	virtual std::string toString(void) const override;
};

class NullableInteger : public __internal::__NullableDiscordParam<int, 0> {
	virtual json11::Json toJson(void) const override;
	virtual std::string toString(void) const override;
};

}
}

#endif