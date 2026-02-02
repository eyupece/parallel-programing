// Fibonacci dizisi - Paralel CPU (Açıkça paralelleştirilemez, örnek için böl-paralelleştir)
#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    const int N = 30;
    int fib[N];
    fib[0] = 0; fib[1] = 1;
    // Sadece ilk iki eleman paralel hesaplanamaz, geri kalanı için böl-paralelleştir
    #pragma omp parallel for schedule(dynamic)
    for (int i = 2; i < N; i++) {
        // Bu örnek, gerçek paralellik sağlamaz, çünkü bağımlılık var!
        fib[i] = fib[i-1] + fib[i-2];
    }
    cout << "fib[" << N-1 << "] = " << fib[N-1] << endl;
    return 0;
}
// Not: Fibonacci dizisi klasik for reduction ile paralelleştirilemez, bu kodda veri yarışları oluşur. Gerçek paralel algoritma için farklı teknikler gerekir.