#include<stdio.h>
#pragma warning(disable:4996)

int max(int X[], int N) {
	int tmp;
	if (N == 0) {
		return X[N];
	}
	else {
		tmp = max(X, N - 1);
		if (X[N] > tmp) return X[N];
		else return tmp;
	}

}

int main() {
	int N;
	scanf("%d", &N);
	int X[20];
	for (int i = 0; i < N; i++) {
		scanf("%d", &X[i]);
	}
	printf("%d\n", max(X, N - 1));

	return 0;
}