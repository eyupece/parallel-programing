#include <omp.h>
#include <iostream>
using namespace std;

int main() {
int cnt = 0;

#pragma omp parallel for
	for(int i = 0;i<1000;i++) {
		#pragma omp atomic
		cnt++;
	}

cout << cnt;
return 0;
}