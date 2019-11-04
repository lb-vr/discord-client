/*#ifndef LBVR_VOICE_VOICEBASE_HPP
#define LBVR_VOICE_VOICEBASE_HPP

#include "../DiscordObjectBase.hpp"
#include "../Types.hpp"

namespace lbvr {
namespace guild {
class GuildMember;
class GuildId;
}
namespace channel {
class ChannelId;
}
namespace user {
class UserId;
}

namespace voice {

/// 
/// Discord document at https://discordapp.com/developers/docs/resources/voice#voice-resource
class VoiceStateBase : public DiscordObjectBase{
protected:
	using guild_member_d	= guild::GuildMember;
	using guild_d			= guild::GuildId;
	using channel_d			= channel::ChannelId;
	using user_d			= user::UserId;

	_base<guild_d>			guild_id_;		///< optional. the guild id this voice state is for.
	_base<channel_d>		channel_id_;	///< nullable. the channel id this user is connected to.
	_base<user_d>			user_id_;		///< the user id this voice state is for.
	_base<guild_member_d>	member_;		///< the guild member this voice state is for.
	_base<string_d>			session_id_;	///< the session id for this voice state.
	_base<boolean_d>		deaf_;			///< whether this user is deafened by the server.
	_base<boolean_d>		mute_;			///< whether this user is muted by the server.
	_base<boolean_d>		self_deaf_;		///< whether this user is locally deafened.
	_base<boolean_d>		self_mute_;		///< whether this user is locally muted.
	_base<boolean_d>		self_stream_;	///< optional. whether this user is streaming using "Go Live".
	_base<boolean_d>		suppress_;		///< whether this user is muted by the current user
};

}
}

#endif
*/