
#include "util.h"
#include <cstdlib>

namespace eoaix {
	int square(int n) {
		return n * n;
	}

	TestKey::TestKey(int val_int, const std::string& val_str):_val_int(val_int), _val_str(val_str) {}

	std::string TestKey::toString() const {
		std::string res(_val_int < 0 ? "-" : "");
		int val = abs(_val_int);
//		return std::to_string(_val_int) + _val_str;

		while(val) {
			res += val% 10 + '0';
			val /= 10;
		}
		res += _val_str;
		return res;
	}

	TestKey::~TestKey() {}
}
