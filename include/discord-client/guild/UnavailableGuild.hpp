#ifndef LBVR_GUILD_UNAVAILABLEGUILDBASE_HPP
#define LBVR_GUILD_UNAVAILABLEGUILDBASE_HPP

#include "../object/__DiscordObjectBase.hpp"

namespace lbvr {
namespace guild{

class UnavailableGuild : public object::__internal::__DiscordObjectBase {
	UnavailableGuild() {}

protected:
	class __Impl;
	std::unique_ptr<__Impl> __impl;
};

}
}

#endif