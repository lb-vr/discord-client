#ifndef LBVR_CHANNEL_CHANNEL_HPP
#define LBVR_CHANNEL_CHANNEL_HPP

#include "../object/__DiscordObjectBase.hpp"

namespace lbvr {
namespace channel {
/// 
/// Discord document at 
class Channel : public object::__internal::__DiscordObjectBase {
public:
	Channel() {}

	virtual json11::Json				toJson(void) const override;
	virtual std::string					toString(void) const override;
protected:
	//class __Impl;
	//std::unique_ptr<__Impl> __impl;
	/*
	_base<snowflake_d>					id_;							///< guild id
	*/
};

}
}

#endif