#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)


typedef struct deque {
	int front;
	int rear;
	int storage[50];
} Deque;


int isoverflow(Deque* D) {
	if ((D->front - D->rear + 50) % 50 == 1) return 1;
	else return 0;
}

int isunderflow(Deque* D) {
	if (D->front == D->rear) return 1;
	else return 0;
}

void init_Deque(Deque* D) {
	D->front = 0;
	D->rear = 0;
	for (int i = 0; i < 30; i++) {
		D->storage[i] = 0;
	}
}

void add_front(Deque* D, int x) {
	D->front = (D->front - 1 + 50) % 50;
	D->storage[D->front] = x;
	return;
}

void add_rear(Deque* D, int x) {
	D->storage[D->rear] = x;
	D->rear = (D->rear + 1) % 50;
	return;
}

int delete_front(Deque* D) {
	int e = D->storage[D->front];
	D->storage[D->front] = 0;
	D->front = (D->front + 1) % 50;

	return e;
}

int delete_rear(Deque* D) {
	int e = D->storage[(D->rear - 1 + 50) % 50];
	D->storage[(D->rear - 1 + 50) % 50] = 0;
	D->rear = (D->rear - 1 + 50) % 50;
	return e;
}
void print(Deque* D) {

	int i = D->front;

	while (D->storage[i] != 0) {
		printf(" %d", D->storage[i]);
		i++;
		if (i > 49) {
			i = 0;
		}
	}
	printf("\n");
}

int main() {

	Deque* D = (Deque*)malloc(sizeof(Deque));

	init_Deque(D);

	int n, x;
	scanf("%d", &n);
	getchar();

	char ch[10];

	for (int i = 0; i < n; i++) {
		scanf("%s", ch);
		getchar();

		if (strcmp(ch, "AF") == 0) {
			scanf("%d", &x);
			getchar();

			if (isoverflow(D)) {
				printf("overflow\n");
				break;
			}
			else {
				add_front(D, x);
			}

		}
		else if (strcmp(ch, "AR") == 0) {
			scanf("%d", &x);
			getchar();

			if (isoverflow(D)) {
				printf("overflow\n");
				break;
			}
			else {
				add_rear(D, x);
			}
		}
		else if (strcmp(ch, "DF") == 0) {
			if (isunderflow(D)) {
				printf("underflow\n");
				break;
			}
			else {
				delete_front(D);
			}
		}
		else if (strcmp(ch, "DR") == 0) {
			if (isunderflow(D)) {
				printf("underflow\n");
				break;
			}
			else {
				delete_rear(D);
			}
		}
		else if (strcmp(ch, "P") == 0) {
			print(D);
		}
	}

	return 0;
}