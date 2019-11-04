#ifndef LBVR_DISCORDOBJECTS_HPP
#define LBVR_DISCORDOBJECTS_HPP

//////////////////////////////////////////////////////////////////////////////////
// Basic Types
#include "types/Base64.hpp"
#include "types/Boolean.hpp"
#include "types/Integer.hpp"
#include "types/Snowflake.hpp"
#include "types/String.hpp"
namespace lbvr {
using base64_d						= types::Base64;
using boolean_d						= types::Boolean;
using integer_d						= types::Integer;
using snowflake_d					= types::Snowflake;
using string_d						= types::String;
template <class T> using array_d	= std::vector<T>;
}

//////////////////////////////////////////////////////////////////////////////////
// Guild Type
#include "guild/Guild.hpp"
#include "guild/ContentFilterLevel.hpp"
#include "guild/GuildFeature.hpp"
#include "guild/GuildMember.hpp"
#include "guild/MessageNotificationLevel.hpp"
#include "guild/MfaLevel.hpp"
#include "guild/PremiumTier.hpp"
#include "guild/UnavailableGuild.hpp"
#include "guild/VerificationLevel.hpp"
namespace lbvr {
using guild_d						= guild::Guild;
using content_filter_level_d		= guild::ContentFilterLevel;
using guild_feature_d				= guild::GuildFeature;
using guild_member_d				= guild::GuildMember;
using message_notification_level_d	= guild::MessageNotificationLevel;
using mfa_level_d					= guild::MfaLevel;
using premium_tier_d				= guild::PremiumTier;
using unavailable_guild_d			= guild::UnavailableGuild;
using verification_level_d			= guild::VerificationLevel;
}

//////////////////////////////////////////////////////////////////////////////////
// Channel
#include "channel/Channel.hpp"
namespace lbvr {
using channel_d						= channel::Channel;
}

//////////////////////////////////////////////////////////////////////////////////
// Role
#include "role/Role.hpp"
namespace lbvr {
using role_d						= role::Role;
}

#endif