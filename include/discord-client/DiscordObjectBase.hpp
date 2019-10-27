#ifndef LBVR_DISCORDOBJECTBASE_HPP
#define LBVR_DISCORDOBJECTBASE_HPP

#include <memory>
#include <string>

namespace lbvr {

class DiscordObjectBase {
public:
	virtual std::string toJsonString(void) const = 0;

protected:
	template <class T>
	using _base = std::unique_ptr<T>;
};

}

#endif