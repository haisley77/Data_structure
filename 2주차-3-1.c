#include<stdio.h>
#include<stdlib.h>

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
		scanf("%d", &X[i]);
	}

	A = prefixAverages1(X, n);
	for (int i = 0; i < n; i++) {
		printf("%d", A[i]);
		if (i == n - 1) printf("\n");
		else printf(" ");
	}
	free(A);


	A = prefixAverages2(X, n);
	for (int i = 0; i < n; i++) {
		printf("%d", A[i]);
		if (i != n) printf(" ");
	}
	free(A);

	free(X);

	return 0;
}