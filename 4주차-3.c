int main() {
	int N;
	scanf("%d", &N);
	int x[100][100];
	int a = 1;

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			for (int k = 0; k < N; k++) {
				x[i][k] = a;
				a++;
			}
		}
		else {
			for (int j = N - 1; j >= 0; j--) {
				x[i][j] = a;
				a++;
			}
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf(" %d", x[i][j]);
		}
		printf("\n");
	}

	return 0;
}