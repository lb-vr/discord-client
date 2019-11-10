#ifndef LBVR_TYPES_TIMESTAMP_HPP
#define LBVR_TYPES_TIMESTAMP_HPP

#include "__DiscordParam.hpp"

namespace lbvr {
namespace types {

namespace __internal {
class __TimestampInitializer {
public:
	constexpr operator time_t() { return 0; }
};
}

class Timestamp : public __internal::__DiscordParam<time_t> {
public:
	using __internal::__DiscordParam<time_t>::__DiscordParam;
	virtual json11::Json toJson(void) const override;
	virtual std::string toString(void) const override;
};

class NullableTimestamp : public __internal::__NullableDiscordParam<time_t, __internal::__TimestampInitializer> {
public:
	using __internal::__NullableDiscordParam<time_t, __internal::__TimestampInitializer>::__NullableDiscordParam;
	virtual json11::Json toJson(void) const override;
	virtual std::string toString(void) const override;
};

}
}

#endif