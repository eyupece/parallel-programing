// Dizi elemanlarını çarpma - Paralel GPU (OpenMP target)
#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int dizi[N];
    for (int i = 0; i < N; i++) dizi[i] = i+1;
    long long carpim = 1;
    #pragma omp target map(tofrom:carpim) map(to:dizi[0:N])
    {
        #pragma omp teams distribute parallel for reduction(*:carpim)
        for (int i = 0; i < N; i++) carpim *= dizi[i];
    }
    cout << "çarpım = " << carpim << endl;
    return 0;
}
