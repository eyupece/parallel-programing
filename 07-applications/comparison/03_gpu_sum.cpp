// Dizi elemanlarını toplama - Paralel GPU (OpenMP target)
#include <iostream>
using namespace std;

int main() {
    const int N = 100000;
    int dizi[N];
    for (int i = 0; i < N; i++) dizi[i] = i;
    long toplam = 0;
    #pragma omp target map(tofrom:toplam) map(to:dizi[0:N])
    {
        #pragma omp teams distribute parallel for reduction(+:toplam)
        for (int i = 0; i < N; i++) toplam += dizi[i];
    }
    cout << "toplam = " << toplam << endl;
    return 0;
}
