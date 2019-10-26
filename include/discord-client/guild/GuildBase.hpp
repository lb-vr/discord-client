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

enum struct GuildFeature {
	INVITE_SPLASH,	///< guild has access to set an invite splash background
	VIP_REGIONS,	///< guild has access to set 384kbps bitrate in voice(previously VIP voice servers)
	VANITY_URL,		///< guild has access to set a vanity URL
	VERIFIED,		///< guild is verified
	PARTNERED,		///< guild is partnered
	PUBLIC,			///< guild is public
	COMMERCE,		///< guild has access to use commerce features(i.e.create store channels)
	NEWS,			///< guild has access to create news channels
	DISCOVERABLE,	///< guild is able to be discovered in the directory
	FEATURABLE,		///< guild is able to be featured in the directory
	ANIMATED_ICON,	///< guild has access to set an animated guild icon
	BANNER,			///< guild has access to set a guild banner image
};
class guild_feature : Param<GuildFeature> {};

enum struct MessageNotificationLevel {
	ALL_MESSAGE = 0,
	ONLY_MENTIONS = 1
};
class message_notification_level_d : Param<MessageNotificationLevel>{};

enum struct ContentFilterLevel {
	DISABLED = 0,
	MEMBER_WITHOUT_ROLES = 1,
	ALL_MEMBERS = 2
};
class content_filter_level_d : Param<ContentFilterLevel> {};

enum struct MfaLevel {
	NONE = 0,
	ELEVATED = 1
};
class mfa_level_d : Param<MfaLevel> {};

enum struct VerificationLevel {
	NONE = 0,	///< unrestricted
	LOW,		///< must have verified email on account
	MEDIUM,		///< must be registered on Discord for longer than 5 minutes
	HIGH,		///< must be a member of the server for longer than 10 minutes
	VERY_HIGH	///< must have a verified phone number
};
class verification_level_d : Param<VerificationLevel> {};

enum PremiumTier {
	NONE = 0,
	TIER_1,
	TIER_2,
	TIER_3
};
class premium_tier_d : Param<PremiumTier> {};

class UnavailableGuildBase : public DiscordObjectBase {
protected:
	_base<snowflake_d>		id_;			///< guild id.
	_base<boolean_d>		unavailable_;	///< whether this guild is unavailable.
};

class GuildEmbedBase : public DiscordObjectBase {
protected:
	_base<snowflake_d>		channel_id_;	///< nullable. the embed channel id.
	_base<boolean_d>		enabled_;		///< whether the embed is enabled.
};

class GuildMemberBase : public DiscordObjectBase {
protected:
	using user_d = user::UserBase;
	using roles_d = array_d<role::RoleID>;
	_base<user_d>			user_;			///< the user this guild member represents.
	_base<string_d>			nick_;			///< optional. this users guild nickname(if one is set).
	_base<roles_d>			roles_;			///< array of role object ids.
	_base<timestamp_d>		joined_at_;		///< when the user joined the guild.
	_base<timestamp_d>		premium_since_;	///< nullable and optional. when the user used their Nitro boost on the server.
	_base<boolean_d>		deaf_;			///< whether the user is deafened in voice channels.
	_base<boolean_d>		mute_;			///< whether the user is muted in voice channels.
};



/// 
/// Discord document at https://discordapp.com/developers/docs/resources/guild
class GuildBase : public DiscordObjectBase{

protected:
	using roles_d				= array_d<role::RoleBase>;
	using emojis_d				= array_d<emoji::EmojiBase>;
	using guild_features_d		= array_d<guild_feature>;
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