#include <omp.h>
#include <iostream>
using namespace std;

int main() {

	#pragma omp parallel
	{
	int id = omp_get_thread_num();

          #pragma omp critical
	        cout << "Thread No :" << id << " Phase 1 done\n";
	
		#pragma omp barrier
        
        #pragma omp critical
	        cout << "Thread No :" << id << " Phase 2 start\n";

	}
return 0;
}