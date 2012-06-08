
#include <util.h>
#include <hash.h>

int main() {
using namespace eoaix;
	HashMap<TestKey, TestKey> htable;

	TestKey t1(1, "1str");
	TestKey t2(2, "2str");

	htable.insert(t1, t2);
	htable.insert(t2, t1);

	TestKey* t3 = htable.find_val(t1);
	
	std::cout << t3->toString() << std::endl;

	return 0;
}
