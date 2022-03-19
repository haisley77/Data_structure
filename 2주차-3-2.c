#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#pragma warning(disable:4996)

int* prefixAverages1(int* X, int n) {
	int sum;
	int* A = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j <= i; j++) {
			sum += X[j];
		}
		A[i] = ((double)sum / (i + 1) + 0.5) / 1;
	}

	return A;
}
int* prefixAverages2(int* X, int n) {
	int sum = 0;
	int* A = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		sum += X[i];
		A[i] = ((double)sum / (i + 1) + 0.5) / 1;
	}

	return A;
}


int main() {
	int n;
	scanf("%d", &n);

	int* X = (int*)malloc(sizeof(int) * n);
	int* A;


	for (int i = 0; i < n; i++) {
		srand(time(NULL));
		X[i] = rand() % 10000 + 1;
	}

	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);

	A = prefixAverages1(X, n);

	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.9fms\n", (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000);

	free(A);

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);


	A = prefixAverages2(X, n);

	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.9fms\n", (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000);

	free(A);

	free(X);


	return 0;
}