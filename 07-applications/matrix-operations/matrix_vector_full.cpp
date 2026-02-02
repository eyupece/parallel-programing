#include <iostream>
#include <vector>
#include <omp.h>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;

using Matrix = vector<vector<double>>;
using FlatMatrix = vector<double>;


class Helper{
    public:
    void printVector(const FlatMatrix& V) {
        for (const auto& val : V) {
            cout << val << " ";
        }
        cout << endl;
    }
    void printMatrix(const Matrix& M) {
        for (const auto& row : M) {
            for (const auto& val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    FlatMatrix generateRandomVector(int size) {
        FlatMatrix V(size);

        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(0.0, 10000.0); 

        for(int i = 0; i < size; i++) {
            V[i] = dis(gen);
        }
        return V;
    }
    Matrix generateRandomMatrix(int rows, int cols) {
        Matrix M(rows, vector<double>(cols));

        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(0.0, 10000.0); 

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                M[i][j] = dis(gen);
            }
        }
        return M;
    }
    FlatMatrix convert2Dto1D(const Matrix& M) {
        int rows = M.size();
        int cols = M[0].size();
        FlatMatrix flatM(rows * cols);

        #pragma omp parallel 
        {
            #pragma omp for
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    flatM[i * cols + j] = M[i][j];
                }
            }
        }
        return flatM;
    }
};

class MatrixVectorMultiplier{
private:
    Helper helper;
public:
    FlatMatrix matrixVectorMultiplySerial(const Matrix& A, const FlatMatrix& B){
        int rowA = A.size();
        int colA = A[0].size();
        int sizeB = B.size();

        if (colA != sizeB) {
            cout << "Error: Dimension mismatch!" << endl;
            return {};
        }

        FlatMatrix C(rowA, 0.0);

        for (int i = 0; i < rowA; i++) {
            double sum = 0.0;
            for (int j = 0; j < colA; j++) {
                sum += A[i][j] * B[j];
            }
            C[i] = sum;
        }
        return C;
    }
    FlatMatrix matrixVectorMultiplyParallel(const Matrix& A, const FlatMatrix& B){
        int rowA = A.size();
        int colA = A[0].size();
        int sizeB = B.size();

        if (colA != sizeB) {
            cout << "Error: Dimension mismatch!" << endl;
            return {};
        }
        FlatMatrix C(rowA, 0.0);
        // Bir thread havuzu oluşturur
        #pragma omp parallel
        {
            // Her işçi (thread) için işi böler
            #pragma omp for
            for (int i = 0; i < rowA; i++) {
                double sum = 0.0;
                // İç döngü seri olarak çalışır
                for (int j = 0; j < colA; j++) {
                    sum += A[i][j] * B[j];
                }
                C[i] = sum;
            }
        }
        return C;
    }
    FlatMatrix matrixVectorMultiplyParallelGPU(const Matrix& A, const FlatMatrix& B){
        int rowA = A.size();
        int colA = A[0].size();
        int sizeB = B.size();

        if (colA != sizeB) {
            cout << "Error: Dimension mismatch!" << endl;
            return {};
        }
        FlatMatrix flatA = helper.convert2Dto1D(A);

        FlatMatrix flatC(rowA, 0.0);

        double *ptrA = flatA.data();
        double *ptrB = const_cast<double*>(B.data());
        double *ptrC = flatC.data();
        
        int sizeA = rowA * colA;
        int sizeC = rowA;

        // Target ile GPU'ya veri transferi ve hesaplama yapılır
        #pragma omp target map(to: ptrA[0:sizeA], ptrB[0:sizeB]) map(from: ptrC[0:sizeC])
        {
            // GPU üzerinde takımlar oluşturur.
            #pragma omp teams
            {
                // For döngüsünü takımlar arasında paylaştırır
                #pragma omp distribute
                for (int i = 0; i < rowA; i++) {
                    double sum = 0.0;
                    // Her takım için işçiler (threadler) oluşturur
                    #pragma omp parallel reduction(+:sum)
                    {
                        // İşçiler (threadler) arasında işi böler
                        #pragma omp for
                        for (int k = 0; k < colA; k++) {
                             sum += ptrA[i * colA + k] * ptrB[k];
                        }                        
                        ptrC[i] = sum;
                    }
                }
            }
        }
        return flatC;
    }
};

int main(){
    MatrixVectorMultiplier multiplier;
    Helper helper;
    int rows = 5000;
    int cols = 5000;
    Matrix A = helper.generateRandomMatrix(rows, cols);
    FlatMatrix B = helper.generateRandomVector(cols);

    auto start = chrono::high_resolution_clock::now();
    multiplier.matrixVectorMultiplySerial(A, B);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> serial_duration = end - start;
    cout << "-- Matrix-Vector Multiplication --" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Serial Duration: " << setprecision(6) << serial_duration.count() << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    multiplier.matrixVectorMultiplyParallel(A, B);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> parallel_duration = end - start;
    cout << "-----------------------------------------" << endl;
    cout << "Parallel Duration: " << setprecision(6) << parallel_duration.count() << " seconds" << endl;


    start = chrono::high_resolution_clock::now();
    multiplier.matrixVectorMultiplyParallelGPU(A, B);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> gpu_duration = end - start;
    cout << "-----------------------------------------" << endl;
    cout << "GPU Duration: " << setprecision(6) << gpu_duration.count() << " seconds" << endl;
    cout << "-----------------------------------------" << endl;

}