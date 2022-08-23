#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


int* movingAverages1(int X[], int n, int k) {
	int sum;
	int* A;
	A = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		sum = 0;
		if (i < k - 1) {
			for (int j = 0; j <= i; j++) {
				sum += X[j];
			}
			A[i] = ((double)sum / (double)(i + 1) + 0.5) / 1;
		}
		else {
			for (int j = i - k + 1; j <= i; j++) {
				sum += X[j];
			}
			A[i] = ((double)sum / (double)k + 0.5) / 1;
		}
	}
	return A;
}

int* movingAverages2(int X[], int n, int k) {
	int sum = 0;
	int* A;
	int num = 0;
	A = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		if (i <= k - 1) {
			sum += X[i];
		}
		else {
			sum += X[i];
			sum -= X[num];
			num++;
		}

		if (i <= k - 1) {
			A[i] = ((double)sum / (double)(i + 1) + 0.5) / 1;
		}
		else {
			A[i] = ((double)sum / (double)k + 0.5) / 1;
		}
	}
	return A;
}


int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	int* X;
	X = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &X[i]);
	}

	int* A;
	A = movingAverages1(X, n, k);

	for (int i = 0; i < n; i++) {
		printf("%d", A[i]);
		if (i == n - 1) printf("\n");
		else printf(" ");
	}

	free(A);

	A = movingAverages2(X, n, k);

	for (int i = 0; i < n; i++) {
		printf("%d", A[i]);
		if (i == n - 1)printf("\n");
		else printf(" ");
	}

	free(A);

	free(X);

	return 0;
}