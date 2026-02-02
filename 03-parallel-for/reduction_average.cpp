#include <omp.h>
#include <iostream>
using namespace std;

int main() {

int a[10] = {1,2,3,4,5,6,7,8,9,10};
int sum = 0;

	#pragma omp parallel for reduction(+:sum)
	for(int i = 0; i<10;i++) {
	sum += a[i];
	}
double avg = double(sum)/10;
cout << avg;
return 0;
}