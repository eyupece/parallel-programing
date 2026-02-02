#include <omp.h>
#include <iostream>
using namespace std;

int main() {

int sum = 0;	
int a[10] = {1,2,3,4,5,6,7,8,9,10};
	
	#pragma omp parallel
	{
	#pragma omp for simd reduction(+:sum)
	for(int i = 0; i < 10; i++) {
	sum += a[i];
	} 
	}
    cout << sum;
return 0;
}