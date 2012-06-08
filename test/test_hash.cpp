#include <util.h>
#include <hash.h>
#include <gtest/gtest.h>

TEST(SquareTest, SquareTest1) {
	EXPECT_EQ(1, eoaix::square(1));	
	EXPECT_EQ(4, eoaix::square(2));	
}

TEST(HashTest, NormalHash) {
	using namespace eoaix;
	HashMap<TestKey, TestKey> htable;

	TestKey t1(1, "1str");
	TestKey t2(2, "2str");

	htable.insert(t1, t2);
	htable.insert(t2, t1);

	TestKey* t3 = htable.find_val(t1);
	
//	std::cout << t3->toString() << std::endl;
	//std::cout << t2.toString() << std::endl;
	EXPECT_EQ(t3->toString(), t2.toString());
}
