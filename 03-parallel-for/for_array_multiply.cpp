#include <omp.h>
#include <iostream>
using namespace std;

int main() {
int a[8] = {2,4,6,8,10,12,14,16};
	#pragma omp parallel for
	for( int i = 0; i<8; i++) {
	a[i] *= 2;
	cout << a[i] << "\n";
	}

return 0;
}