#include<stdio.h>
#pragma warning(disable:4996)

int sum(int N) {
	if (N == 1) return 1;
	if (N > 1) {
		return N + sum(N - 1);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	printf("%d", sum(N));

	return 0;
}