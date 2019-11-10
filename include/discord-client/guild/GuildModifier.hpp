#ifndef LBVR_GUILD_GUILDMODIFIER_HPP
#define LBVR_GUILD_GUILDMODIFIER_HPP

#include "Guild.hpp"

namespace lbvr {
namespace guild {

class GuildModifier {
public:
	GuildModifier(void) noexcept;
	GuildModifier(const Guild & guild);

	const Guild & getGuild(void) const;

	GuildModifier &	setName							(const string_d & name);
	GuildModifier & setVoiceRegionId				(const voice::RegionID & region);
	GuildModifier & setVerificationLevel			(const VerificationLevel & verification_level);
	GuildModifier &	setDefaultMessageNotification	(const MessageNotificationLevel & default_message_notification);
	GuildModifier &	setExplicitContentFilter		(const ContentFilterLevel & explicit_content_filter);
	GuildModifier &	setAfkChannelId					(const channel::ChannelId & afk_channel_id);
	GuildModifier &	setAfkChannelId					(nullptr_t);
	GuildModifier &	setAfkTimeout					(const integer_d & afk_timeout);
	GuildModifier &	setIcon							(const base64_d & icon);
	GuildModifier &	setOwnerId						(const user::UserId & user);
	GuildModifier &	setSplash						(const base64_d & splash);
	GuildModifier &	setBanner						(const string_d & banner);
	GuildModifier &	setBanner						(nullptr_t);
	GuildModifier &	setWidgetChannelId				(const channel::ChannelId & widget_channel_id);

private:
	Guild guild_;
};

}
}

#endif