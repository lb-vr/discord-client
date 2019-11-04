#include "discord-client/guild/GuildCreator.hpp"
#include "discord-client/voice/VoiceRegionId.hpp"
#include "discord-client/channel/ChannelNameAndType.hpp"
#include "discord-client/guild/GuildImpl.hpp"

lbvr::guild::CreateGuild::CreateGuild(
	const string_d & name,
	const voice_region_d & region,
	const base64_d & icon,
	const verification_level_d & verification_level,
	const message_notification_level_d & default_message_notifications,
	const content_filter_level_d & explicit_content_filter,
	const roles_d & roles,
	const channels_d & channels)
{
	this->__impl->name_ = 
}
