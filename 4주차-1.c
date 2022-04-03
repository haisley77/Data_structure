#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int N;
	scanf("%d", &N);
	int x[100];

	for (int i = 0; i < N; i++) {
		scanf("%d", &x[i]);
	}

	int n;
	scanf("%d", &n);

	int a, b;
	int tmp;

	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		while (b - a >= 1) {
			tmp = x[a];
			x[a] = x[b];
			x[b] = tmp;
			a++;
			b--;
		}
	}



	for (int i = 0; i < N; i++) {
		printf(" %d", x[i]);
	}


	return 0;
}