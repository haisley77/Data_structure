#include <stdio.h>

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	int x[100][100] = { 0 };

	int a = 1;
	int row = 0, col = 0;
	
	while (a < N * M) {
		while (col < M - 1 && x[row][col + 1] == 0) {
			x[row][col] = a;
			a++;
			col++;
		}

		while (row < N - 1 && x[row + 1][col] == 0) {
			x[row][col] = a;
			a++;
			row++;
		}

		while (col > 0 && x[row][col - 1] == 0) {
			x[row][col] = a;
			a++;
			col--;
		}

		while (row > 0 && x[row - 1][col] == 0) {
			x[row][col] = a;
			a++;
			row--;
		}
	}
	x[row][col] = a;



	for (row = 0; row < N; row++) {
		for (col = 0; col < M; col++) {
			printf(" %d", x[row][col]);
		}
		printf("\n");
	}


	return 0;
}