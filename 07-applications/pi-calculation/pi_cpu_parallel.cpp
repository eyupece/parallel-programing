#include <iostream>
#include <omp.h>
#include <iomanip>
using namespace std;

int main() {
  const long N = 100000000;
  const double step = 1.0 / (double)N;
  int num_threads = omp_get_max_threads();

  double sum = 0.0;
  double t0 = omp_get_wtime();

  #pragma omp parallel
  {
    #pragma omp for reduction(+:sum) schedule(dynamic,10000)
    for (long i = 0; i < N; i++) {
      double x = (i + 0.5) * step;
      sum += 4.0 / (1.0 + x * x);
    }
  }

  double t1 = omp_get_wtime();
  double pi = sum * step;

  cout << fixed << setprecision(14);
  cout << "pi=" << pi << "\n";
  cout << "threads=" << num_threads << "\n";
  cout << "time=" << (t1 - t0) << "\n";
  return 0;
}