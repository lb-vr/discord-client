#include "discord-client/guild/GuildImpl.hpp"
#include "discord-client/guild/GuildModifier.hpp"
#include "discord-client/channel/ChannelId.hpp"

lbvr::guild::GuildModifier::GuildModifier(void) noexcept
{}

lbvr::guild::GuildModifier::GuildModifier(const Guild & guild) {
	if (guild.hasName())
		this->setName(guild.getName());
	
	if (guild.hasVoiceRegionId())
		this->setVoiceRegionId(guild.getVoiceRegionId());
	
	if (guild.hasDefaultMessageNotification())
		this->setDefaultMessageNotification(guild.getDefaultMessageNotification());

	if (guild.hasExplicitContentFilter())
		this->setExplicitContentFilter(guild.getExplicitContentFilter());

	if (guild.hasAfkChannelId()) {
		if (!guild.getAfkChannelId())
			this->setAfkChannelId(nullptr);
		else this->setAfkChannelId(*guild.getAfkChannelId());
	}

	if (guild.hasAfkTimeout())
		this->setAfkTimeout(guild.getAfkTimeout());

	if (guild.hasIcon())
		this->setIcon(guild.getIcon());

	if (guild.hasOwnerId())
		this->setOwnerId(guild.getOwnerId());

	if (guild.hasSplash())
		this->setSplash(guild.getSplash());

	if (guild.hasBanner()) {
		if (!guild.getBanner())
			this->setBanner(*guild.getBanner());
		else this->setBanner(nullptr);
	}

	if (guild.hasWidgetChannelId())
		this->setWidgetChannelId(guild.getWidgetChannelId());
}

const lbvr::guild::Guild & lbvr::guild::GuildModifier::getGuild(void) const { return this->guild_; }
lbvr::guild::GuildModifier & lbvr::guild::GuildModifier::setName(const string_d & name) {
	this->guild_.setName(name);
	return *this;
}

lbvr::guild::GuildModifier & lbvr::guild::GuildModifier::setVoiceRegionId(const voice::RegionID & region) {
	this->guild_.setVoiceRegionId(region);
	return *this;
}

lbvr::guild::GuildModifier & lbvr::guild::GuildModifier::setVerificationLevel(const VerificationLevel & verification_level) {
	this->guild_.setVerificationLevel(verification_level);
	return *this;
}

lbvr::guild::GuildModifier & lbvr::guild::GuildModifier::setDefaultMessageNotification(const MessageNotificationLevel & default_message_notification) {
	this->guild_.setDefaultMessageNotification(default_message_notification);
	return *this;
}

lbvr::guild::GuildModifier & lbvr::guild::GuildModifier::setExplicitContentFilter(const ContentFilterLevel & explicit_content_filter) {
	this->guild_.setExplicitContentFilter(explicit_content_filter);
	return *this;
}

lbvr::guild::GuildModifier & lbvr::guild::GuildModifier::setAfkChannelId(const channel::ChannelId & afk_channel_id) {
	this->guild_.setAfkChannelId(afk_channel_id);
	return *this;
}

lbvr::guild::GuildModifier & lbvr::guild::GuildModifier::setAfkChannelId(nullptr_t) {
	this->guild_.setAfkChannelId(nullptr);
	return *this;
}

lbvr::guild::GuildModifier & lbvr::guild::GuildModifier::setAfkTimeout(const integer_d & afk_timeout) {
	this->guild_.setAfkTimeout(afk_timeout);
	return *this;
}

lbvr::guild::GuildModifier & lbvr::guild::GuildModifier::setIcon(const base64_d & icon) {
	this->guild_.setIcon(icon);
	return *this;
}

lbvr::guild::GuildModifier & lbvr::guild::GuildModifier::setOwnerId(const user::UserId & user) {
	this->guild_.setOwnerId(user);
	return *this;
}

lbvr::guild::GuildModifier & lbvr::guild::GuildModifier::setSplash(const base64_d & splash) {
	this->guild_.setSplash(splash);
	return *this;
}

lbvr::guild::GuildModifier & lbvr::guild::GuildModifier::setBanner(const string_d & banner) {
	this->guild_.setBanner(banner);
	return *this;
}

lbvr::guild::GuildModifier & lbvr::guild::GuildModifier::setBanner(nullptr_t) {
	this->guild_.setBanner(nullptr);
	return *this;
}

lbvr::guild::GuildModifier & lbvr::guild::GuildModifier::setWidgetChannelId(const channel::ChannelId & widget_channel_id) {
	this->guild_.setWidgetChannelId(widget_channel_id);
	return *this;
}
