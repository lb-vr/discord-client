#include "gtest/gtest.h"
#include "discord-client/types/Base64.hpp"
#include "discord-client/types/Boolean.hpp"
#include "discord-client/types/Enum.hpp"
#include "discord-client/types/Integer.hpp"
#include "discord-client/types/Snowflake.hpp"
#include "discord-client/types/String.hpp"

using namespace lbvr::types;
TEST(Param, IntegerTest) {
	Integer a(10);
	ASSERT_EQ(a.get(), 10);

	a.set(30);
	Integer b = a;

	ASSERT_EQ(a.get(), 30);
	ASSERT_EQ(a.toString(), "30");

	ASSERT_EQ(b.get(), 30);
}

TEST(Param, BooleanTest) {
	Boolean a(true);
	ASSERT_TRUE(a.get());
	ASSERT_EQ(a.toString(), "true");

	a.set(false);
	Boolean b = a;

	ASSERT_FALSE(a.get());
	ASSERT_EQ(a.toString(), "false");

	ASSERT_FALSE(b.get());
}

TEST(Param, StringTest) {
	String a("banana");

	ASSERT_EQ(a.get(), "banana");
	a.set("apple");
	String b = a;

	ASSERT_EQ(a.get(), "apple");
	ASSERT_EQ(a.toString(), "apple");

	ASSERT_EQ(b.get(), "apple");

	auto c = std::move(b);
	ASSERT_EQ(c.get(), "apple");
}


TEST(Param, NullableIntegerTest) {
	NullableInteger a;
	ASSERT_FALSE(a.isSet());
	ASSERT_EQ(a.get(), 0);
	ASSERT_EQ(a.toString(), "null");

	a.set(30);
	NullableInteger b = a;

	ASSERT_EQ(a.get(), 30);
	ASSERT_EQ(a.toString(), "30");

	a.setNull();
	ASSERT_FALSE(a.isSet());
	ASSERT_EQ(a.get(), 0);
	ASSERT_EQ(a.toString(), "null");

	ASSERT_EQ(b.get(), 30);
	ASSERT_EQ(b.toString(), "30");
}

TEST(Param, NullableBooleanTest) {
	NullableBoolean a;
	ASSERT_FALSE(a.get());
	ASSERT_FALSE(a.isSet());
	ASSERT_EQ(a.toString(), "null");

	a.set(false);
	NullableBoolean b = a;

	ASSERT_FALSE(a.get());
	ASSERT_EQ(a.toString(), "false");
	a.set(true);
	ASSERT_TRUE(a.get());
	ASSERT_EQ(a.toString(), "true");
	ASSERT_TRUE(a.isSet());

	a.setNull();
	ASSERT_FALSE(a.isSet());
	ASSERT_FALSE(a.isSet());
	ASSERT_EQ(a.toString(), "null");

	ASSERT_FALSE(b.get());
}

TEST(Param, NullableStringTest) {
	NullableString a;
	ASSERT_EQ(a.get(), "");
	ASSERT_FALSE(a.isSet());
	ASSERT_EQ(a.toString(), "null");
	
	a.set("banana");

	ASSERT_EQ(a.get(), "banana");
	a.set("apple");
	ASSERT_TRUE(a.isSet());

	NullableString b = a;

	ASSERT_EQ(a.get(), "apple");
	ASSERT_EQ(a.toString(), "apple");

	ASSERT_EQ(b.get(), "apple");

	auto c = std::move(b);
	ASSERT_EQ(c.get(), "apple");

	a.setNull();
	ASSERT_FALSE(a.isSet());
}

