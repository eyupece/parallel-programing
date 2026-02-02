#include <cstdio>
#include <cstdlib>
#include <omp.h>

const int N = 16;

int main(int argc, char* argv[]) {
	int* data = (int*)(malloc(N * sizeof(int))); // in C
	//int* data = new int(N * sizeof(int)); // in C++

	int device = omp_get_num_devices();
	printf("Running on %s\n", (device ? "device" : "host"));

	for (int i = 0; i < N; i++)
		data[i] = i;

	#pragma omp target map(from:device) map(tofrom:data[0:N])
	{
		#pragma omp parallel for
		for (int i = 0; i < N; i++) {
			data[i] *= 2;
		}
	}

	for (int i = 0; i < N; i++)
		printf("%d\n", data[i]);

	free(data);  // in C
	//delete data; // in C++

	return 0;
}
