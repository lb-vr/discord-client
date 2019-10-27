#ifndef LBVR_GUILD_GUILDBASE_HPP
#define LBVR_GUILD_GUILDBASE_HPP

#include "../DiscordObjectBase.hpp"
#include "../Types.hpp"

namespace lbvr {

namespace voice {
class VoiceStateNoGuildId;
}
namespace user {
class UserBase;
}
namespace role {
class RoleBase;
class RoleID;
}
namespace emoji {
class EmojiBase;
}
namespace channel {
class ChannelBase;
}
namespace presence {
class PresenceUpdateBase;
}

namespace guild {

// Param
class content_filter_level_d;
class guild_feature_d;
class message_notification_level_d;
class mfa_level_d;
class verification_level_d;
class premium_tier_d;

// BaseClass
class GuildMemberBase;
class UnavailableGuildBase;

/// 
/// Discord document at https://discordapp.com/developers/docs/resources/guild
class GuildBase : public DiscordObjectBase{

protected:
	using roles_d				= array_d<role::RoleBase>;
	using emojis_d				= array_d<emoji::EmojiBase>;
	using guild_features_d		= array_d<guild_feature_d>;
	using voice_states_d		= array_d<voice::VoiceStateNoGuildId>;
	using guild_members_d		= array_d<GuildMemberBase>;
	using channels_d			= array_d<channel::ChannelBase>;
	using presence_updates_d	= array_d<presence::PresenceUpdateBase>;

	_base<snowflake_d>					id_;							///< guild id
	_base<string_d>						name_;							///< guild name (2 - 100 characters)
	_base<base64_d>						icon_;							///< nullable. icon hash.
	_base<base64_d>						splash_;						///< nullable. splash hash.
	_base<boolean_d>					owner_;							///< optional. whether or not the user is the owner of the guild.
	_base<snowflake_d>					owner_id_;						///< id of owner.
	_base<integer_d>					permissions_;					///< optional. total permissions for the user in the guild (does not include channel overrides).
	_base<string_d>						region_;						///< voice region id for the guild.
	_base<snowflake_d>					afk_channel_id_;				///< nullable. id of afk channel.
	_base<integer_d>					afk_timeout_;					///< afk timeout in seconds.
	_base<boolean_d>					embed_enabled_;					///< optional. whether this guild is embeddable(e.g.widget).
	_base<snowflake_d>					embed_channel_id_;				///< optional. if not null, the channel id that the widget will generate an invite to.
	_base<verification_level_d>			verification_level_;			///< verification level required for the guild.
	_base<message_notification_level_d>	default_message_notifications_;	///< default message notifications level.
	_base<content_filter_level_d>		explicit_content_filter_;		///< explicit content filter level.
	_base<roles_d>						roles_;							///< roles in the guild.
	_base<emojis_d>						emojis_;						///< custom guild emojis.
	_base<guild_features_d>				features_;						///< array of guild feature strings	enabled guild features.
	_base<mfa_level_d>					mfa_level_;						///< required MFA level for the guild.
	_base<snowflake_d>					application_id_;				///< nullable. application id of the guild creator if it is bot - created
	_base<boolean_d>					widget_enabled_;				///< optional. whether or not the server widget is enabled.
	_base<snowflake_d>					widget_channel_id_;				///< optional. the channel id for the server widget.
	_base<snowflake_d>					system_channel_id_;				///< nullable. the id of the channel to which system messages are sent.
	_base<timestamp_d>					joined_at_;						///< optional*. ISO8601 timestamp. when this guild was joined at.
	_base<boolean_d>					large_;							///< optional*. whether this is considered a large guild.
	_base<boolean_d>					unavailable_;					///< optional*. whether this guild is unavailable.
	_base<integer_d>					member_count_;					///< optional*. total number of members in this guild.
	_base<voice_states_d>				voice_states_;					///< optional*. (without the guild_id key)
	_base<guild_members_d>				members_;						///< optional*. users in the guild.
	_base<channels_d>					channels_;						///< optional*. channels in the guild.
	_base<presence_updates_d>			presences_;						///< optional*. presences of the users in the guild.
	_base<integer_d>					max_presences_;					///< optional and nullable.
																		///< the maximum amount of presences for the guild.
																		///< (the default value, currently 5000, is in effect when null is returned)
	_base<integer_d>					max_members_;					///< optional. the maximum amount of members for the guild.
	_base<string_d>						vanity_url_code_;				///< nullable. the vanity url code for the guild.
	_base<string_d>						description_;					///< nullable. the description for the guild.
	_base<string_d>						banner_;						///< nullable. banner hash.
	_base<premium_tier_d>				premium_tier_;					///< premium tier.
	_base<integer_d>					premium_subscription_count_;	///< optional. the total number of users currently boosting this server.
	_base<string_d>						preferred_locale_;				///< the preferred locale of this guild only set if guild has the "DISCOVERABLE" feature,
																		///< defaults to en - US
};

}
}

#endif