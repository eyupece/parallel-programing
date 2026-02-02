#include <omp.h>
#include <iostream>
using namespace std;

int main() {
    #pragma omp parallel
    {
        
        int id = omp_get_thread_num();  // her thread'in kendi kimliği (0,1,2,…)
        if (id < 3) {                   // sadece ilk 3 thread için çalışsın
            #pragma omp critical
            cout << "Thread " << id << " says hello!\n";
        }
    }
    return 0;
}
// Derlemek için: g++ -fopenmp helloworld.cpp -o helloworld
// Çalıştırmak için: ./helloworld
