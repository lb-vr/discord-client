#include "gtest/gtest.h"
#include "discord-client/Param.hpp"
#include <string>

using namespace lbvr;
TEST(Param, IntParamTest1) {
	Param<int> param(10);
	ASSERT_EQ(param.get(), 10);
	ASSERT_FALSE(param.isSet());

	param.set(30);
	Param<int> param2 = param;
	ASSERT_TRUE(param.isSet());
	ASSERT_EQ(param.get(), 30);

	param.clear();
	ASSERT_EQ(static_cast<int>(param), 10);
	ASSERT_FALSE(param.isSet());

	ASSERT_TRUE(param2.isSet());
	ASSERT_EQ(param2.get(), 30);
}

TEST(Param, StrParamTest2) {
	Param<std::string> param("banana");
	ASSERT_EQ(param.get(), "banana");
	ASSERT_FALSE(param.isSet());
	param.set("apple");
	Param<std::string> param2 = param;
	ASSERT_TRUE(param.isSet());
	ASSERT_EQ(param.get(), "apple");
	param.clear();
	ASSERT_EQ(static_cast<std::string>(param), "banana");
	ASSERT_FALSE(param.isSet());
	ASSERT_EQ(param.toString(), "A Param");

	ASSERT_TRUE(param2.isSet());
	ASSERT_EQ(param2.get(), "apple");

	auto param3 = std::move(param2);
	ASSERT_TRUE(param3.isSet());
	ASSERT_EQ(param3.get(), "apple");
}
