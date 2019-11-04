#ifndef LBVR_ROLE_ROLEBASE_HPP
#define LBVR_ROLE_ROLEBASE_HPP

#include "../object/__DiscordObjectBase.hpp"

namespace lbvr {
namespace role {

/// 
/// Discord document at https://discordapp.com/developers/docs/resources/voice#voice-resource
class Role : public object::__internal::__DiscordObjectBase {
	Role() {}

protected:
	class __Impl;
	std::unique_ptr<__Impl> __impl;
	
};

}
}

#endif