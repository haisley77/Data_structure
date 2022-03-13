#include<stdio.h>
#pragma warning(disable:4996)

struct student {
	char name[10];
	int s;
};

int main() {
	struct student ary[5];
	int total = 0;
	double avg;

	for (int i = 0; i < 5; i++) {
		scanf("%s%d", &ary[i].name, &ary[i].s);
		total += ary[i].s;
	}
	avg = total / 5.0;

	for (int i = 0; i < 5; i++) {
		if (ary[i].s <= avg) {
			printf("%s\n", ary[i].name);
		}
	}

	return 0;
}