#include "discord-client\types\Snowflake.hpp"

namespace {
uint64_t generateNewSnowflake(void) {
	return 0; // TODO
}
}

lbvr::types::Snowflake::Snowflake(void) noexcept
	: __DiscordParam(generateNewSnowflake())
{}

lbvr::types::Snowflake::~Snowflake(void) noexcept
{}

json11::Json lbvr::types::Snowflake::toJson(void) const {
	return json11::Json(this->toString());
}

std::string lbvr::types::Snowflake::toString(void) const {
	return std::to_string(this->get());
}

std::string lbvr::types::Snowflake::getAsString(void) const {
	return std::to_string(this->get());
}