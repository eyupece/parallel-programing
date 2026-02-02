// Matris çarpımı - Paralel DEĞİL (Çoklu döngü)
#include <iostream>
using namespace std;

int main() {
    const int N = 100;
    int A[N][N], B[N][N], C[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = B[i][j] = i + j;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    cout << "C[0][0] = " << C[0][0] << endl;
    return 0;
}
