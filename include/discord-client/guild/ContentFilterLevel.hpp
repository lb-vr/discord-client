#ifndef LBVR_GUILD_CONTENTFILTERLEVEL_HPP
#define LBVR_GUILD_CONTENTFILTERLEVEL_HPP

#include "../types/Enum.hpp"

namespace lbvr {
namespace guild {

/// @brief content filter level
enum struct ContentFilterLevelEnum {
	DISABLED = 0,
	MEMBER_WITHOUT_ROLES = 1,
	ALL_MEMBERS = 2
};

/// @brief Type of content filter level
class ContentFilterLevel : public types::Enum<ContentFilterLevelEnum> {
public:
	using types::Enum<ContentFilterLevelEnum>::Enum;

	/// @brief toString.
	virtual std::string toString(void) const;
};

}
}

#endif