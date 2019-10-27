#include "discord-client/guild/GuildCreator.hpp"

lbvr::guild::GuildCreator::GuildCreator(
	const string_d & name,
	const voice_region_d & region,
	const base64_d & icon,
	const verification_level_d & verification_level,
	const message_notification_level_d & default_message_notifications,
	const content_filter_level_d & explicit_content_filter,
	const roles_d & roles,
	const channels_d & channels)
{
	name_							= std::make_unique<string_d>(name);
	region_							= std::make_unique<voice_region_d>(region);
	icon_							= std::make_unique<base64_d>(icon);
	verification_level_				= std::make_unique<verification_level_d>(verification_level);
	default_message_notifications_	= std::make_unique<message_notification_level_d>(default_message_notifications);
	explicit_content_filter_		= std::make_unique<content_filter_level_d>(explicit_content_filter);
	roles_							= std::make_unique<roles_d>(roles);
	channels_						= std::make_unique<channels_d>(channels);
}
