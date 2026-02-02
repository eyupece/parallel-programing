#include <iostream>
#include <omp.h>
using namespace std;

int main() {
	#pragma omp parallel
	{
	
		#pragma omp single
		{
			#pragma omp task
			{
			int id = omp_get_thread_num();
			cout << "Load :" << id << "\n";
			}

			#pragma omp task
			{
			int id = omp_get_thread_num();
			cout << "Preprocess :" << id << "\n";
			}

			#pragma omp task
			{
			int id = omp_get_thread_num();
			cout << "Train :" << id << "\n";
			}

            #pragma omp taskwait
      	    cout << "Pipeline done\n";
		}

	}
return 0;
}