#include<stdio.h>
#pragma warning(disable:4996)

int sum(int n) {
	int total = 0;
	for (int i = 1; i <= n; i++) {
		total += i;
	}
	return total;
}

int main() {

	int X;
	scanf("%d", &X);
	int t = 0;
	for (int i = 1; i <= X; i++) {
		t += sum(i);
	}
	printf("%d", t);

	return 0;
}
