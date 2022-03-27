#include<stdio.h>
#pragma warning(disable:4996)

void print_i(int N) {
	if (N == 0) {
		return;
	}
	else {
		print_i(N / 10);
		printf("%d\n", N % 10);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	print_i(N);

	return 0;
}