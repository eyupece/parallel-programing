#include <omp.h>
#include <iostream>
using namespace std;

int main() {

#pragma omp parallel
{
int id = omp_get_thread_num();

    if( id % 2 == 0){
        cout << "Thread" << id << " hi\n";
    }
}

return 0;

}
