/*#include "gtest/gtest.h"
#include "discord-client/Types.hpp"
#include <string>
#include <memory>
using namespace lbvr;
TEST(Param, IntParamTest) {
	integer_d param(10);
	ASSERT_EQ(param.get(), 10);

	param.set(30);
	integer_d param2 = param;
	ASSERT_EQ(param.get(), 30);
	ASSERT_EQ(static_cast<int>(param), 30);
	ASSERT_EQ(param.toString(), "30");

	ASSERT_EQ(param2.get(), 30);
}

TEST(Param, StrParamTest) {
	string_d param("banana");

	ASSERT_EQ(param.get(), "banana");
	param.set("apple");
	string_d param2 = param;
	ASSERT_EQ(param.get(), "apple");
	
	ASSERT_EQ(static_cast<std::string>(param), "apple");
	ASSERT_EQ(param.toString(), "apple");

	ASSERT_EQ(param2.get(), "apple");

	auto param3 = std::move(param2);
	ASSERT_EQ(param3.get(), "apple");
}

TEST(Param, ArrayTest) {
	array_d<integer_d> array_param;
	ASSERT_EQ(array_param.get().size(), 0);
	array_param.add(3);
	array_param.add(4);
	array_param.add(5);
	ASSERT_EQ(array_param.toString(), "( 3, 4, 5 )");
	array_param.set({integer_d(10), integer_d(11)});
	ASSERT_EQ(array_param.toString(), "( 10, 11 )");
}
*/