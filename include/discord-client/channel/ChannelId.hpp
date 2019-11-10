#ifndef LBVR_CHANNEL_CHANNELID_HPP
#define LBVR_CHANNEL_CHANNELID_HPP

#include "Channel.hpp"

namespace lbvr {
namespace channel {

class ChannelId {
public:
	ChannelId() {}
private:
	channel::Channel channel_;
};

}
}

#endif