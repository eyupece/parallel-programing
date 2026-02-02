#include <omp.h>
#include <iostream>
using namespace std;

int main() {

	#pragma omp parallel
	{
	int id = omp_get_thread_num();
		#pragma omp master
		{
		cout << "master only\n";
		}
	cout << "Thread No :" << id << "run\n";
	}

return 0;
}