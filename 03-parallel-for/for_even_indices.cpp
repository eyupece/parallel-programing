#include <omp.h>
#include <iostream>
using namespace std;

int main() {

	#pragma omp parallel for
	
	for(int i = 0; i < 16; i++) {
		if(i % 2 == 0) {
            cout << "i=" << i << "\n";
		}
	}

return 0;
}