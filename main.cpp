#include <iostream>
#include "src/util.h"
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <memory>
using namespace std;

const int Max = 1<<19;

class Node {
	public:
		Node() {
			for(int i = 0; i < Max; ++i) {
				_a[i] = rand();
			}
		}
		Node(const Node& n) {
			for(int i = 0; i < Max; ++i)
				_a[i] = n._a[i];
		}
		void show() {
			for(int i = 0; i < Max; ++i) {
				cout << _a[i] << " ";
			}
			cout << endl;
		}
		int _a[Max];
};

Node funcReturnVal() {
	Node node;
	return node;
}

auto_ptr<Node> funcReturnPointer() {
	auto_ptr<Node> ap(new Node());
	return ap;
}

void testFunc() {
	eoaix::Timer t1;
	for(int i = 0; i < 100; ++i) {
	Node node = funcReturnVal();
	}
	cerr << "funcReturnVal: " << t1.elapsed() << endl;

	t1.reset();
	for(int i = 0; i < 100; ++i) {
	auto_ptr<Node> an = funcReturnPointer();
	}
	cerr << "funcReturnPointer: " << t1.elapsed() << endl;
}

int main(char** argv, int argc) {
	std::cout << "Hello Cmake.\n";
	srand(time(0));
	//testFunc();
	return 0;
}
