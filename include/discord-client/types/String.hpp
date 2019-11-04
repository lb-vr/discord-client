#ifndef LBVR_TYPES_STRING_HPP
#define LBVR_TYPES_STRING_HPP

#include "__DiscordParam.hpp"

namespace lbvr {
namespace types {

class String : public __internal::__DiscordParam<std::string> {
public:
	using __internal::__DiscordParam<std::string>::__DiscordParam;
	virtual json11::Json toJson(void) const override;
	virtual std::string toString(void) const override;
};

class NullableString : public __internal::__NullableDiscordParam<std::string> {
public:
	using __internal::__NullableDiscordParam<std::string>::__NullableDiscordParam;
	virtual json11::Json toJson(void) const override;
	virtual std::string toString(void) const override;
};

}
}

#endif