
// This is a basic util file.
//

#ifndef __BASIC_UTIL_EOAIX__
#define __BASIC_UTIL_EOAIX__

namespace eoaix {

	/*
	   Timer t;
	   t.elapsed() returns the elapse time.
	 */
	class Timer {
		std::clock_t _start;

		public:
		Timer() {
			reset();
		}

		void reset() {
			_start = std::clock();
		}

		double elapsed() {
			return double(std::clock() - _start) /CLOCKS_PER_SEC;   
		}
	};

};

#endif
