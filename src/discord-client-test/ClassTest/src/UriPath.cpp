#include "gtest/gtest.h"
#include "discord-client/UriPath.hpp"

using namespace lbvr;
TEST(UriPath, ReplacePlaceholder1) {
	UriPath path(
		"/this/is/{test}/path", {
			{"test", "right"}
		});
	ASSERT_EQ(path.getUri(), "/this/is/right/path");
	ASSERT_EQ(static_cast<std::string>(path), path.getUri());
}

TEST(UriPath, ReplacePlaceholder2) {
	UriPath path(
		"/this/is/{clientID}/path/huga/{foobar}/aa", {
			{"clientID", "12345"},
			{"foobar", "hogehoge"}
		});

	ASSERT_EQ(path.getUri(), "/this/is/12345/path/huga/hogehoge/aa");
	ASSERT_EQ(static_cast<std::string>(path), path.getUri());
}
