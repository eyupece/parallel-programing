// Fibonacci dizisi - Paralel GPU (Klasik yöntemle doğrudan paralelleştirilemez)
#include <iostream>
using namespace std;

// Not: Fibonacci dizisi klasik döngüyle GPU'da paralelleştirilemez. Gerçek paralel algoritma için farklı teknikler gerekir.
int main() {
    const int N = 30;
    int fib[N];
    fib[0] = 0; fib[1] = 1;
    // GPU'da klasik for ile paralelleştirmek veri yarışına yol açar.
    for (int i = 2; i < N; i++) fib[i] = fib[i-1] + fib[i-2];
    cout << "fib[" << N-1 << "] = " << fib[N-1] << endl;
    return 0;
}
