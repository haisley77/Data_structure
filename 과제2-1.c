#include <stdio.h>


int gcd2(int a, int b) {
	if (a > b) {
		return gcd2(a - b, b);
	}
	else if (a < b) {
		return gcd2(a, b - a);
	}
	else {
		return a;
	}
}


int main() {
	int a, b;
	scanf("%d%d", &a, &b);

	printf("%d\n", gcd2(a, b));
	return 0;
}