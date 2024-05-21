#include <iostream>
using namespace std;
namespace prvi {
	int vrednost() { return 5; }
	namespace drugi {
		double vrednost() { return 4.75; }
	}
}
int main() {
	//using namespace prvi::drugi;
	
	// poziv funkcije vrednost() iz ugnjezdenog namespace
	cout << drugi::vrednost()<< '\n';
	return 0;
}


