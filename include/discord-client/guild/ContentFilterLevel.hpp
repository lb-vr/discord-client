#ifndef LBVR_GUILD_CONTENTFILTERLEVEL_HPP
#define LBVR_GUILD_CONTENTFILTERLEVEL_HPP

#include "../Param.hpp"

namespace lbvr {
namespace guild {

/// @brief content filter level
enum struct ContentFilterLevel {
	DISABLED = 0,
	MEMBER_WITHOUT_ROLES = 1,
	ALL_MEMBERS = 2
};

/// @brief Type of content filter level
class content_filter_level_d : public EnumParam<ContentFilterLevel> {
public:
	using EnumParam<ContentFilterLevel>::EnumParam;

	/// @brief toString.
	virtual std::string toString(void) const noexcept;
};

}
}

#endif