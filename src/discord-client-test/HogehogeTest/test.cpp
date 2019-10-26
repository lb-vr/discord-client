#include "gtest/gtest.h"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(HogehogeTest, TestCaseA) {
	EXPECT_EQ(1, 2);
}

TEST(HogehogeTest, TestCaseB) {
	EXPECT_EQ(2, 2);
}
