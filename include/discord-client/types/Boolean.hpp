#ifndef LBVR_TYPES_BOOLEAN_HPP
#define LBVR_TYPES_BOOLEAN_HPP

#include "__DiscordParam.hpp"

namespace lbvr {
namespace types {

class Boolean : __internal::__DiscordParam<bool> {
	virtual json11::Json toJson(void) const override;
	virtual std::string toString(void) const override;
};

class NullableBoolean : __internal::__NullableDiscordParam<bool, false> {
	virtual json11::Json toJson(void) const override;
	virtual std::string toString(void) const override;
};

}
}

#endif