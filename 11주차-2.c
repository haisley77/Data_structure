
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct node {
	struct node* prev;
	int elem;
	struct node* next;
} Node;

typedef struct deque {
	Node* front;
	Node* rear;
} Deque;

void init(Deque* D);
void add_front(Deque* D, int elem);
void add_rear(Deque* D, int elem);
int delete_front(Deque* D);
int delete_rear(Deque* D);
void print(Deque* D);
int isunderflow(Deque* D);

int main() {

	Deque* D = (Deque*)malloc(sizeof(Deque));
	init(D);

	int n, elem;
	scanf("%d", &n);
	getchar();
	
	char ch[3];
	
	for (int i = 0; i < n; i++) {
		scanf("%s", ch);
		getchar();
	
		if (strcmp(ch, "AF") == 0) {
			scanf("%d", &elem);
			getchar();
			add_front(D, elem);
		}
		else if (strcmp(ch, "AR") == 0) {
			scanf("%d", &elem);
			getchar();
			add_rear(D, elem);
		}
		else if (strcmp(ch, "DF") == 0) {
			if (isunderflow(D)) {
				printf("underflow\n");
				break;
			}
			delete_front(D);
		}
		else if (strcmp(ch, "DR") == 0) {
			if (isunderflow(D)) {
				printf("underflow\n");
				break;
			}
			delete_rear(D);
		}
		else if (strcmp(ch, "P") == 0) {
			print(D);
		}
	}

	return 0;
}



void init(Deque* D) {
	D->front = NULL;
	D->rear = NULL;
}


void add_front(Deque* D, int elem) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->elem = elem;
	if (D->front == NULL) {
		p->next = NULL;
		p->prev = NULL;
		
		D->front = p;
		D->rear = p;
	}
	else {
		p->next = D->front;
		p->prev = NULL;
		D->front = p;
	}
}
void add_rear(Deque* D, int elem) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->elem = elem;
	if (D->rear == NULL) {
		p->next = NULL;
		p->prev = NULL;

		D->front = p;
		D->rear = p;
	}
	else {
		p->next = NULL;
		D->rear->next = p;
		D->rear = p;
	}
}
int delete_front(Deque* D) {
	int e;
	Node* p = D->front;
	e = p->elem;
	if (D->front == D->rear) {
		D->front = NULL;
		D->rear = NULL;
	}
	else {
		D->front = D->front->next;
	}
	free(p);
	return e;
}
int delete_rear(Deque* D) {
	int e;
	Node* p = D->rear;
	e = p->elem;
	if (D->front == D->rear) {
		D->front = NULL;
		D->rear = NULL;
	}
	else {
		D->rear = D->rear->prev;
	}
	free(p);
	return e;
}
void print(Deque* D) {
	Node* p = D->front;
	while (p != NULL) {
		printf(" %d", p->elem);
		p = p->next;
	}
	printf("\n");
	
}
int isunderflow(Deque* D) {
	if (D->front == NULL) return 1;
	else return 0;
}