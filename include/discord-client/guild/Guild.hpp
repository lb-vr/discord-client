#ifndef LBVR_GUILD_GUILD_HPP
#define LBVR_GUILD_GUILD_HPP

#include "../DiscordObjectBase.hpp"

namespace lbvr {
/*
namespace voice {
class VoiceStateNoGuildId;
class VoiceRegionBase;

class VoiceRegionId;
}
namespace user {
class UserBase;
}
namespace role {
class Role;
class RoleID;
}
namespace emoji {
class EmojiBase;
}
namespace channel {
class ChannelBase;
class ChannelNameAndType;
}
namespace presence {
class PresenceUpdateBase;
}*/

namespace guild {
class verification_level_d;
class message_notification_level_d;
class content_filter_level_d;
class guild_feature_d;
using guild_features_d = array_d<guild_feature_d>;

/// 
/// Discord document at https://discordapp.com/developers/docs/resources/guild
class Guild : public DiscordObjectBase{
public:
	Guild() {}

protected:
	class __Impl;
	std::unique_ptr<__Impl> __impl;
};

}
}

#endif