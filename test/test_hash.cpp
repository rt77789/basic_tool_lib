#include <util.h>
#include <hash.h>
#include <gtest/gtest.h>

TEST(SquareTest, SquareTest1) {
	EXPECT_EQ(1, eoaix::square(1));	
	EXPECT_EQ(4, eoaix::square(2));	
}

TEST(HashTest, ObjectHash) {
	using namespace eoaix;
	HashMap<TestKey, TestKey> htable;

	TestKey t1(1, "1str");
	TestKey t2(2, "2str");
	TestKey t4(4, "4str");

	htable.insert(t1, t2);
	htable.insert(t2, t1);

	TestKey* t3 = htable.find_val(t1);
	
//	std::cout << t3->toString() << std::endl;
	//std::cout << t2.toString() << std::endl;
	EXPECT_EQ(t3->toString(), t2.toString());
	EXPECT_EQ(htable.contains(t1), true);
	EXPECT_EQ(htable.contains(t4), false) << "htable.contains(t4) != true\n";
}

#define INT int
#define UNSI unsigned
#define UINT UNSI INT
#define SHORT short
#define USHORT UNSI SHORT
#define LONG long
#define ULONG UNSI LONG
#define LLONG long long
#define ULLONG UNSI LLONG
#define STRING std::string

#define TEST_SPECIALIZE_HASH(ty)		\
TEST(HashTest, ty##Hash) {				\
	using namespace eoaix;				\
	HashMap<ty, TestKey> htable;			\
	TestKey t1(1, "1str");					\
	TestKey t2(2, "2str");					\
	TestKey t4(4, "4str");					\
	htable.insert((ty)(2), t2);				\
	htable.insert((ty)(1), t1);				\
	TestKey* t3 = htable.find_val((ty)(1));	\
	EXPECT_EQ(t3->toString(), t1.toString());	\
	EXPECT_EQ(htable.contains((ty)(1)), true);	\
	EXPECT_EQ(htable.contains((ty)(4)), false) << "htable.contains(t4) != true\n";	\
}	\

//TEST_SPECIALIZE_HASH(int)
TEST_SPECIALIZE_HASH(INT)
TEST_SPECIALIZE_HASH(UINT)
TEST_SPECIALIZE_HASH(SHORT)
TEST_SPECIALIZE_HASH(USHORT)
TEST_SPECIALIZE_HASH(LONG)
TEST_SPECIALIZE_HASH(ULONG)
TEST_SPECIALIZE_HASH(LLONG)
TEST_SPECIALIZE_HASH(ULLONG)


// Test string version.
TEST(HashTest, STRINGHash) {				
	using namespace eoaix;				
	HashMap<std::string, TestKey> htable;			
	TestKey t1(1, "1str");					
	TestKey t2(2, "2str");					
	TestKey t4(4, "4str");					
	htable.insert(std::string("2"), t2);				
	htable.insert(std::string("1"), t1);				
	TestKey* t3 = htable.find_val(std::string("1"));	
	EXPECT_EQ(t3->toString(), t1.toString());	
	EXPECT_EQ(htable.contains(std::string("1")), true);	
	EXPECT_EQ(htable.contains(std::string("4")), false) << "htable.contains(t4) != true\n";	
}	

