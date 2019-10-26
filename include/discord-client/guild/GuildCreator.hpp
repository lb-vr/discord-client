#ifndef LBVR_GUILD_GUILDCREATOR_HPP
#define LBVR_GUILD_GUILDCREATOR_HPP

#include "GuildBase.hpp"

namespace lbvr {

namespace voice {
class VoiceRegionID;
}
namespace channel {
class ChannelNameAndType;
}


namespace guild {

class GuildCreator : public GuildBase {
public:
	using voice_region_d = voice::VoiceRegionID;
	using channels_d = array_d<channel::ChannelNameAndType>;

	explicit GuildCreator(
		const string_d & name,
		const voice_region_d & region,
		const base64_d & icon,
		const verification_level_d & verification_level,
		const message_notification_level_d & default_message_notifications,
		const content_filter_level_d & explicit_content_filter,
		const roles_d & roles,
		const channels_d & channels
	);

};

}
}

#endif