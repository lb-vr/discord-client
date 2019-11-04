#ifndef LBVR_GUILD_MFALEVEL_HPP
#define LBVR_GUILD_MFALEVEL_HPP

#include "../Param.hpp"

namespace lbvr {
namespace guild{

/// @brief mfa level
enum struct MfaLevel {
	NONE = 0,
	ELEVATED = 1
};

/// @brief Type of mfa level.
class mfa_level_d : public EnumParam<MfaLevel> {
public:
	using EnumParam<MfaLevel>::EnumParam;

	/// @brief toString.
	virtual std::string toString(void) const noexcept;
};

}
}

#endif