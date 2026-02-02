#include <omp.h>
#include <iostream>
using namespace std;
int n = 1000;
int main() {

#pragma omp parallel 
#pragma omp for simd schedule(simd:dynamic,4)   // dengesiz iş
for (int i=0; i<n; i++) {
  // work(i)
}


#pragma omp parallel for schedule(static)      // dengeli iş
for (int i=0; i<n; i++) {
  // work(i)
}

#pragma omp parallel for schedule(guided)     // iş yükü azalan şekilde dağıtılır
for (int i=0; i<n; i++) {
  // work(i)
} 
return 0;
}
// Bu kod bu haliyle çalışmaz. Pratik için bu şekilde bıraktım.
