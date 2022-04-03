#include<stdio.h>

int main() {
	int N, M;
	int x[100][100];
	scanf("%d%d", &N, &M);

	int row = 0, col = 0;

	int a = 1;
	int c, r;

	for (col = 0; col < M; col++) {
		row = 0;
		c = col;
		while (c >= 0 && row < N - 1) {
			x[row][c] = a;
			a++;
			row++;
			c--;
		}
	}

	for (row = 0; row < N; row++) {
		col = M - 1;
		r = row;
		while (r < N && col >= 0) {
			x[r][col] = a;
			a++;
			r++;
			col--;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf(" %d", x[i][j]);
		}
		printf("\n");
	}

	return 0;
}