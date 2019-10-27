#include "discord-client\guild\ContentFilterLevel.hpp"

std::string lbvr::guild::content_filter_level_d::toString(void) const noexcept {
	switch (this->get()) {
	case ContentFilterLevel::DISABLED:
		return "ContentFilterLevel::DISABLED";
	case ContentFilterLevel::MEMBER_WITHOUT_ROLES:
		return "ContentFilterLevel::MEMBER_WITHOUT_ROLES";
	case ContentFilterLevel::ALL_MEMBERS:
		return "ContentFilterLevel::ALL_MEMBERS";
	}
	return "UNKNOWN";
}

int lbvr::guild::content_filter_level_d::getAsInt(void) const noexcept {
	return static_cast<int>(this->get());
}

json11::Json lbvr::guild::content_filter_level_d::toJson(void) const noexcept {
	return json11::Json(this->getAsInt());
}