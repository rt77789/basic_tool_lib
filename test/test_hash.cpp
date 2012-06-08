#include <util.h>
#include <gtest/gtest.h>

TEST(SquareTest, SquareTest1) {
	EXPECT_EQ(1, eoaix::square(1));	
	EXPECT_EQ(4, eoaix::square(2));	
}

