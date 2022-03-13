#include<stdio.h>
#pragma warning(disable:4996)

void ABC(int p[], int k) {
	int max = p[k];
	int n = k;
	int temp;
	for (int i = k; i < 10; i++) {
		if (max < p[i]) {
			max = p[i];
			n = i;
		}
	}
	temp = p[k];
	p[k] = p[n];
	p[n] = temp;
}

int main() {
	int p[10];
	for (int k = 0; k < 10; k++) {
		scanf("%d", &p[k]);
	}
	for (int k = 0; k < 10; k++) {
		ABC(p, k);
	}
	for (int i = 0; i < 10; i++) {
		printf(" %d", p[i]);
	}
	return 0;
}