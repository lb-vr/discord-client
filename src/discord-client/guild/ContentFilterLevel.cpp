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
