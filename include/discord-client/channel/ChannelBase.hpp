#ifndef LBVR_CHANNEL_CHANNELBASE_HPP
#define LBVR_CHANNEL_CHANNELBASE_HPP

#include "../DiscordObjectBase.hpp"
#include "../Types.hpp"

namespace lbvr {
namespace channel {
/// 
/// Discord document at 
class ChannelBase : public DiscordObjectBase {
protected:

	_base<snowflake_d>					id_;							///< guild id
	
};

}
}

#endif