#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	int N;
	scanf("%d", &N);

	int x[100];
	int p[101];
	for (int i = 0; i < N; i++) {
		scanf("%d", &x[i]);
	}

	int n;
	scanf("%d", &n);


	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}


	int tmp = x[p[n - 2]];
	for (int i = n - 2; i > 0; i--) {
		x[p[i]] = x[p[i - 1]];
		
	}
	x[p[0]] = tmp;


	for (int i = 0; i < N; i++) {
		printf(" %d", x[i]);
	}

	

	return 0;
}