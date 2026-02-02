#include <omp.h>
#include <iostream>
using namespace std;

int main() {
  #pragma omp parallel
  {
    #pragma omp sections
    {
      #pragma omp section
      {
        int id = omp_get_thread_num();
        #pragma omp critical
        cout << "Loading Data by Thread Id: " << id << "\n";
      }

      #pragma omp section
      {
        int id = omp_get_thread_num();
        #pragma omp critical
        cout << "Preprocessing by Thread Id: " << id << "\n";
      }

      #pragma omp section
      {
        int id = omp_get_thread_num();
        #pragma omp critical
        cout << "Training by Thread Id: " << id << "\n";
      }
    }
  }
  return 0;
}
