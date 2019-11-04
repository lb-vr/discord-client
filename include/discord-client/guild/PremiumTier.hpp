#ifndef LBVR_GUILD_PREMIUMTIER_HPP
#define LBVR_GUILD_PREMIUMTIER_HPP

#include "../Types.hpp"

namespace lbvr {
namespace guild {

enum PremiumTier {
	NONE = 0,
	TIER_1,
	TIER_2,
	TIER_3
};

class premium_tier_d : public EnumParam<PremiumTier> {
public:
	using EnumParam<PremiumTier>::EnumParam;

	/// @brief toString.
	virtual std::string toString(void) const noexcept;
};

}
}

#endif