#ifndef LBVR_GUILD_GUILD_HPP
#define LBVR_GUILD_GUILD_HPP

#include "../object/__DiscordObjectBase.hpp"

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

/// 
/// Discord document at https://discordapp.com/developers/docs/resources/guild
class Guild : public object::__internal::__DiscordObjectBase {
public:
	Guild() {}

protected:
	//class __Impl;
	//std::unique_ptr<__Impl> __impl;
};

}
}

#endif