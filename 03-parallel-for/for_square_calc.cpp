#include <omp.h>
#include <iostream>
using namespace std;

int main() 
{

    #pragma omp parallel for 
    
        for(int i = 0; i<9; i++) {
            cout << i*i;
        }

    
    return 0;
}