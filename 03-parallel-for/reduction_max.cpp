#include <omp.h>
#include <iostream>
using namespace std;

int main(){

int a[8] = {3, 11, 2, 9, 17, 6, 1, 10};
int mx = a[0];

	#pragma omp parallel for reduction(max:mx)
	for(int i = 0;i<8; i++) {
		if(a[i] > mx) {
		mx = a[i];
		}
	
	} 
cout <<mx;
return 0;
}