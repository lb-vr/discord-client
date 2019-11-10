#include "discord-client/guild/GuildImpl.hpp"

#include "discord-client/guild/GuildId.hpp"
#include "discord-client/guild/GuildModifier.hpp"

#include "discord-client/Request.hpp"
#include "discord-client/json11.hpp"

lbvr::guild::Guild lbvr::guild::Guild::modify(const GuildId & guild_id, const GuildModifier & guild_mod) {
	Request req(
		Request::PATCH,
		UriPath("/guilds/{guild.id}", { {"guild.id", guild_id.getGuild().getId().getAsString()} }),
		guild_mod.getGuild().toJson()
	);
	auto res = req.send();
	return Guild(res);
}

lbvr::guild::GuildException::GuildException(const std::string & message, const Guild & guild)
	: std::invalid_argument(message), guild_detail_(guild.toString())
{}
