#ifndef LBVR_GUILD_MESSAGENOTIFICATIONLEVEL_HPP
#define LBVR_GUILD_MESSAGENOTIFICATIONLEVEL_HPP

#include "../Param.hpp"

namespace lbvr {
namespace guild {

/// @brief message notification level.
enum struct MessageNotificationLevel {
	ALL_MESSAGE = 0,
	ONLY_MENTIONS = 1
};

class message_notification_level_d : public EnumParam<MessageNotificationLevel> {
public:
	using EnumParam<MessageNotificationLevel>::EnumParam;

	/// @brief toString.
	virtual std::string toString(void) const noexcept;
};

}
}

#endif