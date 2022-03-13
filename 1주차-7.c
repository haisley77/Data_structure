#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main() {
	int N;
	int* ary1, * ary2;

	scanf("%d", &N);
	ary1 = (int*)malloc(sizeof(int) * N);
	ary2 = (int*)malloc(sizeof(int) * N);



	for (int i = 0; i < N; i++) {
		scanf("%d", &ary1[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &ary2[i]);
	}



	for (int i = 0; i < N; i++) {
		printf(" %d", ary1[i] + ary2[N - i - 1]);

	}

	free(ary1);
	free(ary2);


	return 0;
}