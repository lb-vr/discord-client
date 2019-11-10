#ifndef LBVR_GUILD_GUILDID_HPP
#define LBVR_GUILD_GUILDID_HPP

#include "Guild.hpp"

namespace lbvr {
namespace guild {

class GuildId {
public:

	/// @brief Constructor with id.
	/// @param id Guild ID.
	GuildId(const snowflake_d & id) noexcept;
	
	/// @brief Constructor with Guild instance.
	/// @param guild Guild instance. ID is required.
	/// @throw GuildException guild argument has no ID.
	GuildId(const Guild & guild);

	const Guild & getGuild(void) const;

	GuildId & setId(const snowflake_d & id);

private:
	Guild guild_;
};

}
}

#endif