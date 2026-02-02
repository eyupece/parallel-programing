// Dizi içinde maksimumu bulma - Paralel CPU (OpenMP)
#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    const int N = 1000;
    int dizi[N];
    for (int i = 0; i < N; i++) dizi[i] = rand();
    int maksimum = dizi[0];
    #pragma omp parallel for reduction(max:maksimum)
    for (int i = 1; i < N; i++) if (dizi[i] > maksimum) maksimum = dizi[i];
    cout << "maksimum = " << maksimum << endl;
    return 0;
}
