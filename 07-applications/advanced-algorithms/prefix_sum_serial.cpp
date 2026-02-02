// Prefix sum (kümülatif toplam) - Paralel DEĞİL (Bağımlı döngü)
#include <iostream>
using namespace std;

int main() {
    const int N = 100;
    int dizi[N], toplam[N];
    for (int i = 0; i < N; i++) dizi[i] = i;
    toplam[0] = dizi[0];
    for (int i = 1; i < N; i++) toplam[i] = toplam[i-1] + dizi[i];
    cout << "toplam[" << N-1 << "] = " << toplam[N-1] << endl;
    return 0;
}
