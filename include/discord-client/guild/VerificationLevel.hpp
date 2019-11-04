#ifndef LBVR_GUILD_VERIFICATIONLEVEL_HPP
#define LBVR_GUILD_VERIFICATIONLEVEL_HPP

#include "GuildBase.hpp"

namespace lbvr {
namespace guild {

/// @brief verification level.
enum struct VerificationLevel {
	NONE = 0,	///< unrestricted
	LOW,		///< must have verified email on account
	MEDIUM,		///< must be registered on Discord for longer than 5 minutes
	HIGH,		///< must be a member of the server for longer than 10 minutes
	VERY_HIGH	///< must have a verified phone number
};

/// @brief Type of verification level.
class verification_level_d : public EnumParam<VerificationLevel> {
public:
	using EnumParam<VerificationLevel>::EnumParam;
};

}
}

#endif