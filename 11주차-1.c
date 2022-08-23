
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct que {
	int* storage;
	int front;
	int rear;
	int q;
} Que;

void init_que(Que* Q, int q) {
	Q->storage = (int*)malloc(sizeof(int) * q);
	
	for (int i = 0; i < q; i++) {
		Q->storage[i] = 0;
	}
	Q->front = 0;
	Q->rear = 0;
	Q->q = q;

	return;
}

void insert(Que* Q, int e) {
	Q->rear = (Q->rear + 1) % (Q->q);
	Q->storage[Q->rear] = e;
	return;
}

void delete(Que* Q) {
	Q->front = (Q->front + 1) % (Q->q);
	Q->storage[Q->front] = 0;
	return;
}

void print(Que* Q) {
	int n = Q->q;

	for (int i = 0; i < n; i++) {
		printf(" %d", Q->storage[i]);
	}
	printf("\n");
	return;
}

int isoverflow(Que* Q) {
	if (Q->front == (Q->rear + 1) % (Q->q)) return 1;
	else return 0;
}

int isunderflow(Que* Q) {
	if (Q->front == Q->rear) return 1;
	else return 0;
}



int main() {

	Que* Q = (Que*)malloc(sizeof(Que));

	int q,n,e;
	char ch;
	scanf("%d", &q);
	getchar();
	scanf("%d", &n);
	getchar();

	init_que(Q, q);


	for (int i = 0; i < n; i++) {
		scanf("%c", &ch);
		getchar();

		if (ch == 'I') {
			scanf("%d", &e);
			getchar();

			if (isoverflow(Q) == 1) {
				printf("overflow");
				print(Q);
				break;
			}
			else {
				insert(Q, e);
			}
			
		}
		else if (ch == 'D') {
			if (isunderflow(Q) == 1) {
				printf("underflow");
				break;
			}
			else {
				delete(Q);
			}
		}
		else if (ch == 'P') {
			print(Q);
		}
	}



	return 0;
}
