#ifndef LBVR_GUILD_UNAVAILABLEGUILDBASE_HPP
#define LBVR_GUILD_UNAVAILABLEGUILDBASE_HPP

#include "../Types.hpp"
#include "../DiscordObjectBase.hpp"

namespace lbvr {
namespace guild{

class UnavailableGuildBase : public DiscordObjectBase {
protected:
	_base<snowflake_d>		id_;			///< guild id.
	_base<boolean_d>		unavailable_;	///< whether this guild is unavailable.
};

};

}
}

#endif