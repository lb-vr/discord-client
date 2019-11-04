#ifndef LBVR_GUILD_GUILDFEATURE_HPP
#define LBVR_GUILD_GUILDFEATURE_HPP

#include "../types/Enum.hpp"

namespace lbvr{
namespace guild {

enum struct GuildFeatureEnum {
	INVITE_SPLASH,	///< guild has access to set an invite splash background
	VIP_REGIONS,	///< guild has access to set 384kbps bitrate in voice(previously VIP voice servers)
	VANITY_URL,		///< guild has access to set a vanity URL
	VERIFIED,		///< guild is verified
	PARTNERED,		///< guild is partnered
	PUBLIC,			///< guild is public
	COMMERCE,		///< guild has access to use commerce features(i.e.create store channels)
	NEWS,			///< guild has access to create news channels
	DISCOVERABLE,	///< guild is able to be discovered in the directory
	FEATURABLE,		///< guild is able to be featured in the directory
	ANIMATED_ICON,	///< guild has access to set an animated guild icon
	BANNER,			///< guild has access to set a guild banner image
};
class GuildFeature : public types::Enum<GuildFeatureEnum> {
public:
	using types::Enum<GuildFeatureEnum>::Enum;

	/// @brief toString.
	virtual std::string toString(void) const noexcept;
};

}
}

#endif