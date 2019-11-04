#ifndef LBVR_GUILD_VERIFICATIONLEVEL_HPP
#define LBVR_GUILD_VERIFICATIONLEVEL_HPP

#include "../types/Enum.hpp"

namespace lbvr {
namespace guild {

/// @brief verification level.
enum struct VerificationLevelEnum {
	NONE = 0,	///< unrestricted
	LOW,		///< must have verified email on account
	MEDIUM,		///< must be registered on Discord for longer than 5 minutes
	HIGH,		///< must be a member of the server for longer than 10 minutes
	VERY_HIGH	///< must have a verified phone number
};

/// @brief Type of verification level.
class VerificationLevel : public types::Enum<VerificationLevelEnum> {
public:
	using types::Enum<VerificationLevelEnum>::Enum;

	/// @brief toString.
	virtual std::string toString(void) const noexcept;
};

}
}

#endif