#include "discord-client\types\String.hpp"

json11::Json lbvr::types::String::toJson(void) const {
	return json11::Json(this->get());
}

std::string lbvr::types::String::toString(void) const {
	return this->get();
}

json11::Json lbvr::types::NullableString::toJson(void) const {
	return (this->isSet() ? json11::Json(this->get()) : json11::Json(nullptr));
}

std::string lbvr::types::NullableString::toString(void) const {
	return (this->isSet() ? this->get() : "null");
}
