#include<stdio.h>

int mostOnes(int A[][100], int n) {
	int row;
	int i = 0, j = 0;

	while (1) {

		while (A[i][j] == 1) {
			j += 1;
			if (j == n) return i;
		}
		row = i;
		while (A[i][j] == 0) {
			i += 1;
			if (i == n) return row;
		}
	}

}


int main() {
	int n, i, j;
	int A[100][100];

	scanf("%d", &n);


	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	printf("%d", mostOnes(A, n));

	return 0;
}