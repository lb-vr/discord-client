#ifndef LBVR_GUILD_GUILDEMBEDBASE_HPP
#define LBVR_GUILD_GUILDEMBEDBASE_HPP

#include "../Types.hpp"
#include "../DiscordObjectBase.hpp"

namespace lbvr {
namespace guild {

class GuildEmbedBase : public DiscordObjectBase {
protected:
	_base<snowflake_d>		channel_id_;	///< nullable. the embed channel id.
	_base<boolean_d>		enabled_;		///< whether the embed is enabled.
};

}
}

#endif