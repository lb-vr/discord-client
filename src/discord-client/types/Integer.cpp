#include "discord-client\types\Integer.hpp"
#include <string>

json11::Json lbvr::types::Integer::toJson(void) const {
	return json11::Json(this->get());
}

std::string lbvr::types::Integer::toString(void) const {
	return std::to_string(this->get());
}

json11::Json lbvr::types::NullableInteger::toJson(void) const {
	if (this->isSet()) return json11::Json(this->get());
	return json11::Json(nullptr);
}

std::string lbvr::types::NullableInteger::toString(void) const {
	return (this->isSet() ? std::to_string(this->get()) : "null");
}
