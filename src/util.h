
// This is a basic util file.
//

#ifndef __BASIC_UTIL_EOAIX__
#define __BASIC_UTIL_EOAIX__

#include <iostream>

namespace eoaix {

	/*
	   Timer t;
	   t.elapsed() returns the elapse time.
	 */
	class Timer {
		clock_t _start;

		public:
		Timer() {
			reset();
		}

		void reset() {
			_start = clock();
		}

		double elapsed() {
			return double(clock() - _start) /CLOCKS_PER_SEC;   
		}
	};

	int square(int n);

	class TestKey {
		int _val_int;
		std::string _val_str;

		public:
			TestKey(int val_int, const std::string& val_str);
			~TestKey();

			std::string toString() const;
	};

	void test_func() {
		// This is a test function.
	}
}

#endif
