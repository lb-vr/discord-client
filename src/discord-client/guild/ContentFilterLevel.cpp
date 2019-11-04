#include "discord-client\guild\ContentFilterLevel.hpp"

std::string lbvr::guild::ContentFilterLevel::toString(void) const {
	switch (this->get()) {
	case ContentFilterLevelEnum::DISABLED:
		return "ContentFilterLevel::DISABLED";
	case ContentFilterLevelEnum::MEMBER_WITHOUT_ROLES:
		return "ContentFilterLevel::MEMBER_WITHOUT_ROLES";
	case ContentFilterLevelEnum::ALL_MEMBERS:
		return "ContentFilterLevel::ALL_MEMBERS";
	}
	return "UNKNOWN";
}
