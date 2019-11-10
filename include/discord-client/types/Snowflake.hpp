#ifndef LBVR_TYPES_SNOWFLAKE_HPP
#define LBVR_TYPES_SNOWFLAKE_HPP

#include "__DiscordParam.hpp"

namespace lbvr {
namespace types {

class Snowflake : public __internal::__DiscordParam<uint64_t> {
public:
	Snowflake(void) noexcept;
	virtual ~Snowflake(void) noexcept;
	virtual json11::Json toJson(void) const override;
	virtual std::string toString(void) const override;
	std::string getAsString(void) const;
};

}
}

#endif