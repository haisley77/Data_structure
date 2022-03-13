#include<stdio.h>
#pragma warning(disable:4996)

int main() {

	char p[101];
	char temp;
	int i, size;

	scanf("%s", p);

	for (i = 0; p[i] != '\0'; i++);
	size = i;

	i = 0;
	while (i < size) {
		printf("%s\n", p);
		for (int j = 0; j < size - 1; j++) {
			temp = p[j];
			p[j] = p[j + 1];
			p[j + 1] = temp;
		}
		i++;
	}

	return 0;
}
