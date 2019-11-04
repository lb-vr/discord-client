#ifndef LBVR_GUILD_MFALEVEL_HPP
#define LBVR_GUILD_MFALEVEL_HPP

#include "../types/Enum.hpp"

namespace lbvr {
namespace guild{

/// @brief mfa level
enum struct MfaLevelEnum {
	NONE = 0,
	ELEVATED = 1
};

/// @brief Type of mfa level.
class MfaLevel : public types::Enum<MfaLevelEnum> {
public:
	using types::Enum<MfaLevelEnum>::Enum;

	/// @brief toString.
	virtual std::string toString(void) const noexcept;
};

}
}

#endif