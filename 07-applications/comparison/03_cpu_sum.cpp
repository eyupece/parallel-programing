// Dizi elemanlarını toplama - Paralel CPU (OpenMP)
#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    const int N = 100000;
    int dizi[N];
    for (int i = 0; i < N; i++) dizi[i] = i;
    long toplam = 0;
    #pragma omp parallel for reduction(+:toplam)
    for (int i = 0; i < N; i++) toplam += dizi[i];
    cout << "toplam = " << toplam << endl;
    return 0;
}
