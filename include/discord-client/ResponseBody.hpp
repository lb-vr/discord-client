#ifndef LBVR_REQUESTBODY_HPP
#define LBVR_REQUESTBODY_HPP

#include "BodyBase.hpp"

namespace lbvr {

class RequestBody : public BodyBase{
public:
	RequestBody() {}

	virtual std::string toJsonString(void) const = 0;
private:
};

}

#endif