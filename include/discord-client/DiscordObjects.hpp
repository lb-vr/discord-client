#ifndef LBVR_DISCORDOBJECTS_HPP
#define LBVR_DISCORDOBJECTS_HPP

#include <vector>
#include <memory>

namespace lbvr {

//////////////////////////////////////////////////////////////////////////////////
// Basic Types
namespace types {
class Base64;
class Boolean;
class Integer;
class Snowflake;
class String;
class Timestamp;
}

using base64_d						= types::Base64;
using boolean_d						= types::Boolean;
using integer_d						= types::Integer;
using snowflake_d					= types::Snowflake;
using string_d						= types::String;
using timestamp_d					= types::Timestamp;
template <class T> using nullable	= std::unique_ptr<T>;
template <class T> using array_d	= std::vector<T>;

//////////////////////////////////////////////////////////////////////////////////
// Guild Type
namespace guild {
class Guild;
class GuildId;

class ContentFilterLevel;
class GuildFeature;
class GuildMember;
class GuildModifier;
class GuildMemberModifier;
class GuildEmbed;
class GuildEmbedModifier;
class MessageNotificationLevel;
class MfaLevel;
class PremiumTier;
class UnavailableGuild;
class VerificationLevel;
class PresenceUpdate;
class Ban;
class Invite;
class InviteVanityUrl;
class Integration;
class IntegrationId;
class WidgetStyleOptions;
}

//////////////////////////////////////////////////////////////////////////////////
// Channel
namespace channel {
class Channel;
class ChannelId;
class NullableChannelId;
class NewChannel;
}


//////////////////////////////////////////////////////////////////////////////////
// Role
namespace role {
class Role;
class RoleId;
class RoleModifier;
}

//////////////////////////////////////////////////////////////////////////////////
// Voice
namespace voice {
class RegionID;
class State;
}

//////////////////////////////////////////////////////////////////////////////////
// User
namespace user {
class User;
class UserId;
}


//////////////////////////////////////////////////////////////////////////////////
// Emoji
namespace emoji {
class Emoji;
}

}
#endif