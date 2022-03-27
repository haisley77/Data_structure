#include<stdio.h>
#pragma warning(disalbe:4996)

int count(char p[], char ch, int i) {
	if (i == 0) {
		if (p[i] == ch) return 1;
		else return 0;
	}
	else {
		if (p[i] == ch) return 1 + count(p, ch, i - 1);
		else return count(p, ch, i - 1);
	}

}

int main() {
	char p[101];
	scanf("%s", p);
	getchar();
	char ch;
	scanf("%c", &ch);

	int i;
	for (i = 0; p[i] != '\0'; i++);
	printf("%d\n", count(p, ch, i - 1));

	return 0;
}