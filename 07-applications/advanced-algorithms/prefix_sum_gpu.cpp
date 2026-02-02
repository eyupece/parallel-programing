// Prefix sum (kümülatif toplam) - Paralel GPU (Klasik yöntemle doğrudan paralelleştirilemez)
#include <iostream>
using namespace std;

// Not: Prefix sum için GPU'da özel algoritmalar gerekir (ör. Blelloch scan). Klasik döngüyle doğrudan paralelleştirilemez.
int main() {
    const int N = 100;
    int dizi[N], toplam[N];
    for (int i = 0; i < N; i++) dizi[i] = i;
    toplam[0] = dizi[0];
    for (int i = 1; i < N; i++) toplam[i] = toplam[i-1] + dizi[i];
    cout << "toplam[" << N-1 << "] = " << toplam[N-1] << endl;
    return 0;
}
