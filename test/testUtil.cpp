#include <iostream>
#include <cstdlib>
#include "../util.h"

int main(char **argv, int argc) {
	eoaix::Timer t;
	
	//for(long i = 0; i < (1L<<32); ++i);
	for(long i = 0; i < (1L<<32); ++i);

	std::cout << t.elapsed() << std::endl;
	return 0;
}
