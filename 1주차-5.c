#include<stdio.h>
#pragma warning(disable:4996)

struct time {
	int h;
	int m;
	int s;
};

int main() {
	struct time t1;
	struct time t2;

	scanf("%d%d%d", &t1.h, &t1.m, &t1.s);
	scanf("%d%d%d", &t2.h, &t2.m, &t2.s);

	int a, b, c;
	a = t1.h * 3600 + t1.m * 60 + t1.s;
	b = t2.h * 3600 + t2.m * 60 + t2.s;
	c = b - a;

	struct time t3;

	t3.h = c / 3600;
	t3.m = c % 3600 / 60;
	t3.s = c % 3600 % 60;

	printf("%d %d %d", t3.h, t3.m, t3.s);

	return 0;
}