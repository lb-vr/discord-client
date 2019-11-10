#ifndef LBVR_OBJECT_INTERNAL_DISCORDOBJECTBASE_HPP
#define LBVR_OBJECT_INTERNAL_DISCORDOBJECTBASE_HPP

#include "../DiscordObjects.hpp"
#include <memory>

namespace json11 {
class Json;
}

namespace lbvr {
namespace object {
namespace __internal {

class __DiscordObjectBase {
public:
	virtual json11::Json toJson(void) const = 0;
	virtual std::string toString(void) const = 0;

};


}
}
}

#endif