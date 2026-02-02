#include <omp.h>
#include <iostream>
using namespace std;

int main() {

	#pragma omp parallel 
    {
	    int id = omp_get_thread_num();
	        #pragma omp single nowait
	        {
	        cout << "Setup Done\n";
	        }
	
	cout << "Thread" << id << "running\n";
	}

return 0;
}