#ifndef LBVR_GUILD_IMPL_HPP
#define LBVR_GUILD_IMPL_HPP

#include "Guild.hpp"
#include "../types/Base64.hpp"
#include "../types/Boolean.hpp"
#include "../types/Integer.hpp"
#include "../types/Snowflake.hpp"
#include "../types/String.hpp"
#include "../types/Timestamp.hpp"

namespace lbvr {
namespace guild {

class Guild::__Impl {
public:
	snowflake_d						id_;							///< guild id
	string_d						name_;							///< guild name (2 - 100 characters)
	nullable<base64_d>				icon_;							///< nullable. icon hash.
	nullable<base64_d>				splash_;						///< nullable. splash hash.
	boolean_d						owner_;							///< optional. whether or not the user is the owner of the guild.
	snowflake_d						owner_id_;						///< id of owner.
	integer_d						permissions_;					///< optional. total permissions for the user in the guild (does not include channel overrides).
//	voice_region_d					region_;						///< voice region id for the guild.
	nullable<snowflake_d>			afk_channel_id_;				///< nullable. id of afk channel.
	integer_d						afk_timeout_;					///< afk timeout in seconds.
	boolean_d						embed_enabled_;					///< optional. whether this guild is embeddable(e.g.widget).
	snowflake_d						embed_channel_id_;				///< optional. if not null, the channel id that the widget will generate an invite to.
//	verification_level_d			verification_level_;			///< verification level required for the guild.
//	message_notification_level_d	default_message_notifications_;	///< default message notifications level.
//	content_filter_level_d			explicit_content_filter_;		///< explicit content filter level.
//	roles_d							roles_;							///< roles in the guild.
//	emojis_d						emojis_;						///< custom guild emojis.
//	guild_features_d				features_;						///< array of guild feature strings	enabled guild features.
//	mfa_level_d						mfa_level_;						///< required MFA level for the guild.
	nullable<snowflake_d>			application_id_;				///< nullable. application id of the guild creator if it is bot - created
	boolean_d						widget_enabled_;				///< optional. whether or not the server widget is enabled.
	snowflake_d						widget_channel_id_;				///< optional. the channel id for the server widget.
	nullable<snowflake_d>			system_channel_id_;				///< nullable. the id of the channel to which system messages are sent.
	timestamp_d						joined_at_;						///< optional*. ISO8601 timestamp. when this guild was joined at.
	boolean_d						large_;							///< optional*. whether this is considered a large guild.
	boolean_d						unavailable_;					///< optional*. whether this guild is unavailable.
	integer_d						member_count_;					///< optional*. total number of members in this guild.
//	voice_states_d>					voice_states_;					///< optional*. (without the guild_id key)
//	guild_members_d>				members_;						///< optional*. users in the guild.
//	channels_d>						channels_;						///< optional*. channels in the guild.
//	_base<presence_updates_d>		presences_;						///< optional*. presences of the users in the guild.
	nullable<integer_d>				max_presences_;					///< optional and nullable.
																	///< the maximum amount of presences for the guild.
																	///< (the default value, currently 5000, is in effect when null is returned)
	integer_d						max_members_;					///< optional. the maximum amount of members for the guild.
	nullable<string_d>				vanity_url_code_;				///< nullable. the vanity url code for the guild.
	nullable<string_d>				description_;					///< nullable. the description for the guild.
	nullable<string_d>				banner_;						///< nullable. banner hash.
//	premium_tier_d>					premium_tier_;					///< premium tier.
	integer_d						premium_subscription_count_;	///< optional. the total number of users currently boosting this server.
	string_d						preferred_locale_;				///< the preferred locale of this guild only set if guild has the "DISCOVERABLE" feature,
																		///< defaults to en - US
};

}
}

#endif