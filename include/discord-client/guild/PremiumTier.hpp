#ifndef LBVR_GUILD_PREMIUMTIER_HPP
#define LBVR_GUILD_PREMIUMTIER_HPP

#include "../types/Enum.hpp"

namespace lbvr {
namespace guild {

enum PremiumTierEnum {
	NONE = 0,
	TIER_1,
	TIER_2,
	TIER_3
};

class PremiumTier : public types::Enum<PremiumTierEnum> {
public:
	using types::Enum<PremiumTierEnum>::Enum;

	/// @brief toString.
	virtual std::string toString(void) const noexcept;
};

}
}

#endif