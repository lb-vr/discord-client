#include "discord-client/guild/GuildId.hpp"
#include "discord-client/guild/GuildImpl.hpp"
#include "discord-client/types/Snowflake.hpp"

lbvr::guild::GuildId::GuildId(const snowflake_d & id) noexcept  {
	this->guild_.setId(id);
}

lbvr::guild::GuildId::GuildId(const Guild & guild) {
	if (guild.hasId()) {
		this->setId(guild.getId());
	}
	else throw GuildException("The argument \"guild\" must have id to use GuildId Constructor.", guild);
}

const lbvr::guild::Guild & lbvr::guild::GuildId::getGuild(void) const {
	return this->guild_;
}

lbvr::guild::GuildId & lbvr::guild::GuildId::setId(const snowflake_d & id) {
	this->guild_.setId(id);
	return *this;
}
