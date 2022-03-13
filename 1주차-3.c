#include<stdio.h>
#pragma warning(disable:4996)

void swap(int* pa, int* pb) {
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

int main() {
	int a, b, N;
	int ary[50];
	int* p;
	scanf("%d", &N);
	for (p = ary; p < ary + N; p++) {
		scanf("%d", p);
	}

	scanf("%d%d", &a, &b);
	swap(ary + a, ary + b);

	for (int i = 0; i < N; i++) {
		printf(" %d", ary[i]);
	}

	return 0;
}