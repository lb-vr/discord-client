#ifndef LBVR_TYPES_BOOLEAN_HPP
#define LBVR_TYPES_BOOLEAN_HPP

#include "__DiscordParam.hpp"

namespace lbvr {
namespace types {

class Boolean : public __internal::__DiscordParam<bool> {
public:
	virtual json11::Json toJson(void) const override;
	virtual std::string toString(void) const override;
};

class NullableBoolean : public __internal::__NullableDiscordParam<bool, false> {
public:
	virtual json11::Json toJson(void) const override;
	virtual std::string toString(void) const override;
};

}
}

#endif