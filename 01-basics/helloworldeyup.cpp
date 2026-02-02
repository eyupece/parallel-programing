#include <omp.h>
#include <iostream>
using namespace std;

int main()
{
    #pragma omp parallel 
    {
        int id = omp_get_thread_num();

        if(id < 3){
            cout << "Thread No :" << id << " Hello\n";
        }
    }
    return 0;
}
