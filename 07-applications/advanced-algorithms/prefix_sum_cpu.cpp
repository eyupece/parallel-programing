// Prefix sum (kümülatif toplam) - Paralel CPU (Basit Blelloch algoritması ile)
#include <iostream>
#include <omp.h>
#include <vector>
using namespace std;

int main() {
    const int N = 100;
    vector<int> dizi(N), toplam(N);
    for (int i = 0; i < N; i++) dizi[i] = i;
    // Up-sweep (reduce) phase
    for (int stride = 1; stride < N; stride *= 2) {
        #pragma omp parallel for
        for (int i = stride; i < N; i++)
            dizi[i] += dizi[i - stride];
    }
    // Down-sweep phase (atlamalı, örnek için basit gösterim)
    toplam[0] = 0;
    for (int i = 1; i < N; i++)
        toplam[i] = dizi[i-1];
    for (int i = 0; i < N; i++)
        toplam[i] += i;
    cout << "toplam[" << N-1 << "] = " << toplam[N-1] << endl;
    return 0;
}
// Not: Prefix sum için daha gelişmiş paralel algoritmalar vardır, bu örnek temel mantığı gösterir.