#include "discord-client\types\Timestamp.hpp"

#include <ctime>
#include <iomanip>
#include <sstream>
#include <cstdlib>

namespace {
constexpr char* kTimestampStringFormat = "%FT%T.000000%z";
}

json11::Json lbvr::types::Timestamp::toJson(void) const {
	return json11::Json(this->toString());
}

std::string lbvr::types::Timestamp::toString(void) const {
	std::stringstream ss;
	std::time_t _value = this->get();
	const tm* __value = std::localtime(&_value);
	ss << std::put_time(__value, kTimestampStringFormat);
	return ss.str();
}

json11::Json lbvr::types::NullableTimestamp::toJson(void) const {
	if (this->isSet()) return json11::Json(this->toString());
	return json11::Json(nullptr);
}

std::string lbvr::types::NullableTimestamp::toString(void) const {
	if (this->isSet()) {
		std::stringstream ss;
		std::time_t _value = this->get();
		const tm* __value = std::localtime(&_value);
		ss << std::put_time(__value, kTimestampStringFormat);
		return ss.str();
	}
	return "null";
}
