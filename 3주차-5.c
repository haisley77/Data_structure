#include<stdio.h>
#pragma warning(disable:4996);

void rHanoi(int N, char from, char aux, char to) {
	if (N == 1) {
		printf("%c %c\n", from, to);
	}
	else {
		rHanoi(N - 1, from, to, aux);
		printf("%c %c\n", from, to);
		rHanoi(N - 1, aux, from, to);
		return;
	}
}


int main() {
	int N;
	scanf("%d", &N);
	rHanoi(N, 'A', 'B', 'C');

	return 0;
}