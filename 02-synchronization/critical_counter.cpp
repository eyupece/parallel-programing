#include <omp.h>
#include <iostream>
using namespace std;

int main() {

    #pragma omp parallel for
        for(int i = 0;i<10;i++){
        int id = omp_get_thread_num();
        #pragma omp critical 
        cout << "Thread " << id << " = " << i << "\n";
        
    }
return 0;
}