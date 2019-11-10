#ifndef LBVR_GUILD_GUILD_HPP
#define LBVR_GUILD_GUILD_HPP

#include "../object/__DiscordObjectBase.hpp"

namespace lbvr {
namespace guild {

/// 
/// Discord document at https://discordapp.com/developers/docs/resources/guild
class Guild : public object::__internal::__DiscordObjectBase {
public:
	Guild() noexcept {}
	Guild(const json11::Json & json) noexcept;
	//Guild(const Guild & cp);

	bool								hasId(void) const;
	const snowflake_d &					getId(void) const;
	Guild &								setId(const snowflake_d & id);

	bool								hasName(void) const;
	const string_d &					getName(void) const;
	Guild &								setName(const string_d & name);

	bool								hasIcon(void) const;
	const base64_d &					getIcon(void) const;
	Guild &								setIcon(const base64_d & icon);

	bool								hasSplash(void) const;
	const base64_d &					getSplash(void) const;
	Guild &								setSplash(const base64_d & splash);

	const boolean_d &					getIsOwner(void) const;
	bool								hasIsOwner(void) const;
	Guild &								setIsOwner(const boolean_d & is_owner);

	bool								hasOwnerId(void) const;
	const user::UserId &				getOwnerId(void) const;
	Guild &								setOwnerId(const user::UserId & user);

	bool								hasPermissions(void) const;
	const integer_d &					getPermissions(void) const;
	Guild &								setPermissions(const integer_d & permissions);

	bool								hasVoiceRegionId(void) const;
	const voice::RegionID &				getVoiceRegionId(void) const;
	Guild &								setVoiceRegionId(const voice::RegionID & voice_region_id);

	bool								hasAfkChannelId(void) const;
	nullable<channel::ChannelId>		getAfkChannelId(void) const;
	Guild &								setAfkChannelId(const channel::ChannelId & afk_channel_id);
	Guild &								setAfkChannelId(nullptr_t);

	bool								hasAfkTimeout(void) const;
	const integer_d &					getAfkTimeout(void) const;
	Guild &								setAfkTimeout(const integer_d & afk_timeout);

	bool								hasEmbedEnabled(void) const;
	const boolean_d &					getEmbedEnabled(void) const;
	Guild &								setEmbedEnabled(const boolean_d & embed_enabled);
	
	bool								hasEmbedChannelId(void) const;
	const channel::ChannelId &			getEmbedChannelId(void) const;
	Guild &								setEmbedChannelId(const channel::ChannelId & embed_channel_id);

	bool								hasVerificationLevel(void) const;
	const VerificationLevel &			getVerificationLevel(void) const;
	Guild &								setVerificationLevel(const VerificationLevel & velrification_level);
	
	bool								hasDefaultMessageNotification(void) const;
	const MessageNotificationLevel &	getDefaultMessageNotification(void) const;
	Guild &								setDefaultMessageNotification(const MessageNotificationLevel & default_message_notification);

	bool								hasExplicitContentFilter(void) const;
	const ContentFilterLevel &			getExplicitContentFilter(void) const;
	Guild &								setExplicitContentFilter(const ContentFilterLevel & explicit_content_filter);

	bool								hasRoles(void) const;
	const array_d<role::Role> &			getRoles(void) const;
	Guild &								setRoles(const array_d<role::Role> & roles);

	bool								hasEmojis(void) const;
	const array_d<emoji::Emoji> &		getEmojis(void) const;
	Guild &								setEmojis(const array_d<emoji::Emoji> & emojis);

	bool								hasFeatures(void) const;
	const array_d<GuildFeature>	&		getFeatures(void) const;
	Guild &								setFeatures(const array_d<GuildFeature> & features);

	bool								hasMfaLevel(void) const;
	const MfaLevel &					getMfaLevel(void) const;
	Guild &								setMfaLevel(const MfaLevel & mfa_level);

	// TODO
	bool								hasApplicationId(void) const;
	nullable<snowflake_d>				getApplicationId(void) const;
	Guild &								setApplicationId(const snowflake_d & application_id);
	Guild &								setApplicationId(nullptr_t);

	bool								hasWidgetEnabled(void) const;
	const boolean_d &					getWidgetEnabled(void) const;
	Guild &								setWidgetEnabled(const boolean_d & widget_enabled);

	bool								hasWidgetChannelId(void) const;
	const channel::ChannelId &			getWidgetChannelId(void) const;
	Guild &								setWidgetChannelId(const channel::ChannelId & widget_channel_id);

	bool								hasSystemChannelId(void) const;
	const channel::ChannelId			getSystemChannelId(void) const;
	Guild &								setSystemChannelId(const channel::ChannelId & system_channel_id);

	bool								hasJoinedAt(void) const;
	const timestamp_d &					getJoinedAt(void) const;
	Guild &								setJoinedAt(const timestamp_d & joined_at);

	bool								hasIsLargeGuild(void) const;
	const boolean_d &					getIsLargeGuild(void) const;
	Guild &								setIsLargeGuild(const boolean_d & is_large_guild);

	bool								hasUnavailable(void) const;
	const boolean_d &					getUnavailable(void) const;
	Guild &								setUnavailable(const boolean_d & unavailable);

	bool								hasMemberCount(void) const;
	const integer_d &					getMemberCount(void) const;
	Guild &								setMemberCount(const integer_d & member_count);

	bool								hasVoiceStates(void) const;
	const array_d<voice::State>	&		getVoiceStates(void) const;
	Guild &								setVoiceStates(const array_d<voice::State> & states);

	bool								hasMembers(void) const;
	const array_d<GuildMember> &		getMembers(void) const;
	Guild &								setMembers(const array_d<GuildMember> & members);

	bool								hasChannels(void) const;
	const array_d<channel::Channel>	&	getChannels(void) const;
	Guild &								setChannels(const array_d<channel::Channel> & channels);

	bool								hasPresences(void) const;
	const array_d<PresenceUpdate> &		getPresences(void) const;
	Guild &								setPresences(const array_d<PresenceUpdate> & presences);

	bool								hasMaxPresences(void) const;
	const nullable<integer_d> &			getMaxPresences(void) const;
	Guild &								setMaxPresences(const integer_d & max_presences);
	Guild &								setMaxPresences(nullptr_t);

	bool								hasMaxMembers(void) const;
	const integer_d &					getMaxMembers(void) const;
	Guild &								setMaxMembers(const integer_d & max_members);
	
	bool								hasVanityUrlCode(void) const;
	const nullable<string_d> &			getVanityUrlCode(void) const;
	Guild &								setVanityUrlCode(const string_d & vanity_url_code);
	Guild &								setVanityUrlCody(nullptr_t);

	bool								hasDescription(void) const;
	const nullable<string_d> &			getDescription(void) const;
	Guild &								setDescription(const string_d & description);
	Guild &								setDescription(nullptr_t);

	bool								hasBanner(void) const;
	const nullable<string_d>			getBanner(void) const;
	Guild &								setBanner(const string_d & banner);
	Guild &								setBanner(nullptr_t);

	bool								hasPremiumTier(void) const;
	const PremiumTier &					getPremiumTier(void) const;
	Guild &								setPremiumTier(const PremiumTier & premium_tier);

	bool								hasPremiumSubscriptionCount(void) const;
	const integer_d &					getPremiumSubscriptionCount(void) const;
	Guild &								setPremiumSubscriptionCount(const integer_d & premium_subscription_count);

	bool								hasPreferredLocale(void) const;
	const string_d &					getPreferredLocale(void) const;
	Guild &								setPreferredLocale(const string_d & preferred_locale);

	virtual json11::Json				toJson(void) const override;
	virtual std::string					toString(void) const override;

	static Guild create(
		const string_d &						name,
		const voice::RegionID &					voice_region_id,
		const base64_d &						icon,
		const VerificationLevel &				verification_level,
		const MessageNotificationLevel &		default_message_notifications,
		const ContentFilterLevel &				explicit_content_filter,
		const array_d<role::Role> &				roles,
		const array_d<channel::NewChannel> &	new_channels);

	static Guild get(
		const GuildId &							guild_id
	);
	static Guild get(
		const Guild &							guild_id
	);

	static Guild modify(
		const GuildId &							guild_id,
		const GuildModifier &					guild_mod
	);

	static bool changeChannelPosition(
		const GuildId &							guild_id,
		const channel::ChannelId &				channel_id,
		const integer_d &						position
	);

	static GuildMember getGuildMember(
		const GuildId &							guild_id,
		const user::UserId &					user_id
	);

	static array_d<GuildMember> listGuildMembers(
		const integer_d	&						limit,
		const user::UserId &					after
	);

	static array_d<GuildMember> listGuildMembers(
		const integer_d	&						limit
	);

	static array_d<GuildMember> listGuildMembers(
		const user::UserId &					after
	);

	static array_d<GuildMember> listGuildMembers(void);

	static GuildMember addGuildMember(
		const GuildId &							guild_id,
		const user::UserId &					user_id,
		const string_d &						access_token,
		const string_d &						nick,
		const array_d<role::RoleId> &			roles,
		const boolean_d &						mute,
		const boolean_d &						deaf
	);

	static bool modifyGuildMember(
		const GuildId &							guild_id,
		const user::UserId &					user_id,
		const GuildMemberModifier &				modifier
	);

	static bool changeCurrentUserNick(
		const GuildId &							guild_id,
		const string_d &						nick
	);

	static bool addGuildMemberIntoRole(
		const GuildId &							guild_id,
		const user::UserId &					user_id,
		const role::RoleId &					role_id
	);

	static bool removeGuildMemberFromRole(
		const GuildId &							guild_id,
		const user::UserId &					user_id,
		const role::RoleId &					role_id
	);

	static bool removeGuildMember(
		const GuildId &							guild_id,
		const user::UserId &					user_id
	);

	static array_d<Ban> getGuildBans(
		const GuildId &							guild_id
	);

	static Ban getGuildBan(
		const GuildId &							guild_id,
		const user::UserId &					user_id
	);

	static bool createGuildBan(
		const GuildId &							guild_id,
		const user::UserId &					user_id,
		const integer_d &						delete_message_days,
		const string_d &						reason
	);

	static bool createGuildBan(
		const GuildId &							guild_id,
		const user::UserId &					user_id,
		const integer_d &						delete_message_days
	);

	static bool createGuildBan(
		const GuildId &							guild_id,
		const user::UserId &					user_id,
		const string_d &						reason
	);

	static bool createGuildBan(
		const GuildId &							guild_id,
		const user::UserId &					user_id
	);

	static bool removeGuildBan(
		const GuildId &							guild_id,
		const user::UserId &					user_id
	);

	static array_d<role::Role> getGuildRoles(
		const GuildId &							guild_id
	);

	static role::Role createGuildRole(
		const GuildId &							guild_id,
		const role::Role &						new_role
	);

	static array_d<role::Role> changeGuildRolePosition(
		const GuildId &							guild_id,
		const role::RoleId &					role_id,
		const integer_d &						position
	);

	static bool modifyGuildRole(
		const GuildId &							guild_id,
		const role::RoleId &					role_id,
		const role::RoleModifier &				role_modifier
	);

	static bool deleteGuildRole(
		const GuildId &							guild_id,
		const role::RoleId &					role_id
	);

	static integer_d getGuildPruneCount(
		const GuildId &							guild_id,
		const integer_d &						days
	);

	static integer_d getGuildPruneCount(
		const GuildId &							guild_id
	);

	static integer_d beginGuildPrune(
		const GuildId &							guild_id,
		const integer_d &						days,
		const boolean_d &						compute_prune_count
	);

	static array_d<voice::RegionID> getGuildVoiceRegions(
		const GuildId &							guild_id
	);

	static array_d<Invite> getGuildInvites(
		const GuildId &							guild_id
	);

	static array_d<Integration> getGuildIntegrations(
		const GuildId &							guild_id
	);

	static bool modifyGuildIntegration(
		const GuildId &							guild_id,
		const IntegrationId &					integration_id,
		const integer_d &						expire_behavior,
		const integer_d &						expire_grace_period,
		const boolean_d &						enable_emoticons
	);

	static bool deleteGuildIntegration(
		const GuildId &							guild_id,
		const IntegrationId &					integration_id
	);

	static bool syncGuildIntegration(
		const GuildId &							guild_id,
		const IntegrationId &					integeration_id
	);

	static GuildEmbed getGuildEmbed(
		const GuildId &							guild_id
	);

	static GuildEmbed modifyGuildEmbed(
		const GuildId &							guild_id,
		const GuildEmbedModifier &				guild_embed_modifier
	);

	static InviteVanityUrl getGuildVanityURL(
		const GuildId &							guild_id
	);

	static base64_d getGuildWidgetImage(
		const GuildId &							guild_id,
		const WidgetStyleOptions				style
	);

	static base64_d getGuildWidgetImageOfShield(
		const GuildId &							guild_id
	);

protected:
	class __Impl;
	std::unique_ptr<__Impl> __impl;
};


class GuildException : public std::invalid_argument {
public:
	using std::invalid_argument::invalid_argument;
	GuildException(const std::string & message, const Guild & guild);
private:
	std::string guild_detail_;
};

}
}

#endif