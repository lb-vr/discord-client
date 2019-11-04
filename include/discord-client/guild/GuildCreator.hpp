#ifndef LBVR_GUILD_GUILDCREATOR_HPP
#define LBVR_GUILD_GUILDCREATOR_HPP

#include "Guild.hpp"
#include "../voice/VoiceStateBase.hpp"

namespace lbvr {

namespace role {
class Role;
}
namespace channel {
class ChannelNameAndType;
}

namespace guild {

class CreateGuild : public Guild {
public:
	using roles_d						= array_d<role::RoleBase>;
	using channels_d					= array_d<channel::ChannelNameAndType>;

	CreateGuild(
		const string_d & name,
		const voice::VoiceRegionId & region,
		const base64_d & icon,
		const verification_level_d & verification_level,
		const message_notification_level_d & default_message_notifications,
		const ContentFilterLevel & explicit_content_filter,
		const array_d<role::RoleBase> & roles,
		const array_d<channel::ChannelNameAndType> & channels
	);
};

class GetGuild : public Guild {
public:
	GetGuild(
		const snowflake_d & guild_id
	);
};

class ModifyGuild : public Guild {
public:
	ModifyGuild(
		const snowflake_d & guild_id
	);
};

class DeleteGuild : public Guild {
	DeleteGuild(
		const snowflake_d & guild_id
	);
};

class GetGuildChannels : public Guild {
	GetGuildChannels(
		const snowflake_d & guild_id
	);
};

class ModifyGuildChannelPosition : public Guild {
	ModifyGuildChannelPosition(
		const snowflake_d & guild_id
	);
};

class GetGuildMember : public Guild {
	GetGuildMember(
		const snowflake_d & guild_id
	);
};


}
}

#endif