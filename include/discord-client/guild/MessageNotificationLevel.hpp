#ifndef LBVR_GUILD_MESSAGENOTIFICATIONLEVEL_HPP
#define LBVR_GUILD_MESSAGENOTIFICATIONLEVEL_HPP

#include "../types/Enum.hpp"

namespace lbvr {
namespace guild {

/// @brief message notification level.
enum struct MessageNotificationLevelEnum {
	ALL_MESSAGE = 0,
	ONLY_MENTIONS = 1
};

class MessageNotificationLevel : public types::Enum<MessageNotificationLevelEnum> {
public:
	using types::Enum<MessageNotificationLevelEnum>::Enum;

	/// @brief toString.
	virtual std::string toString(void) const noexcept;
};

}
}

#endif