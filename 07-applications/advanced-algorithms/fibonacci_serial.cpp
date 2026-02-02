// Fibonacci dizisi - Paralel DEĞİL (Bağımlı döngü)
#include <iostream>
using namespace std;

int main() {
    const int N = 30;
    int fib[N];
    fib[0] = 0; fib[1] = 1;
    for (int i = 2; i < N; i++) fib[i] = fib[i-1] + fib[i-2];
    cout << "fib[" << N-1 << "] = " << fib[N-1] << endl;
    return 0;
}
