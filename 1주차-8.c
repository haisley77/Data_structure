#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct student {
	char name[8];
	int a;
	int b;
	int c;
	double avg;
};

int main() {
	int N;
	scanf("%d", &N);
	struct student* s;
	s = (struct student*)malloc(sizeof(struct student) * N);

	for (int i = 0; i < N; i++) {
		scanf("%s%d%d%d", &s[i].name, &s[i].a, &s[i].b, &s[i].c);
		s[i].avg = (s[i].a + s[i].b + s[i].c) / 3.0;
	}

	for (int i = 0; i < N; i++) {

		printf("%s %.1lf", s[i].name, s[i].avg);

		if (s[i].a >= 90 || s[i].b >= 90 || s[i].c >= 90) {
			printf(" GREAT");
		}
		if (s[i].a < 70 || s[i].b < 70 || s[i].c < 70) {
			printf(" BAD");
		}

		printf("\n");
	}

	free(s);

	return 0;

}