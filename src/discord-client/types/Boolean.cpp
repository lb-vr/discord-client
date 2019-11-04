#include "discord-client\types\Boolean.hpp"

json11::Json lbvr::types::Boolean::toJson(void) const {
	return json11::Json(this->get());
}

std::string lbvr::types::Boolean::toString(void) const {
	return (this->get() ? "true" : "false");
}

json11::Json lbvr::types::NullableBoolean::toJson(void) const {
	return (this->isSet() ? json11::Json(this->get()) : json11::Json(nullptr));
}

std::string lbvr::types::NullableBoolean::toString(void) const {
	return (this->isSet() ? (this->get() ? "true" : "false") : "null");
}
