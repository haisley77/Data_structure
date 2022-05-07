#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int elem;
	struct node* next;
} Node;

typedef struct list {
	Node* head;
	Node* k;
} List;

List* init_(List* A) {

	Node* a = (Node*)malloc(sizeof(Node));
	A->head = a;
	A->k = a;
	a->elem = 0;
	a->next = NULL;

	int n;
	scanf("%d", &n);

	if (n == 0) {
		a = NULL;
	}

	for (int i = 0; i < n; i++) {
		Node* tmp = (Node*)malloc(sizeof(Node));
		scanf("%d", &(tmp->elem));	
		tmp->next = NULL;
		A->k->next = tmp;
		A->k = tmp;	
	}
	return A;
}

char member(int e, Node* B) {
	Node* p = (Node*)malloc(sizeof(Node));
	p = B;
	if (B == NULL) {
		return 'F';
	}
	while (1) {
		if (p->elem == e) {
			return 'T';
		}
		else if (p->elem < e) {
			if (p->next == NULL) return 'F';
			else p = p->next;
		}
		else {
			return 'F';
		}
	}
}


int subset(Node* A, Node* B) {
	if (A == NULL) {
		return 0;
	}
	Node* p = (Node*)malloc(sizeof(Node));
	p = A;
	while (1) {
		if (member(p->elem, B) == 'T') {
			if (p->next == NULL) return 0;
			else {
				p = p->next;
			}
		}
		else {
			return p->elem;
		}
	}
}

int main() {
	List* A = (List*)malloc(sizeof(List));
	List* B = (List*)malloc(sizeof(List));
	//A, B 리스트 선언

	A = init_(A);
	B = init_(B);
	//A, B 집합 원소 입력 받기

	printf("%d\n", subset(A->head, B->head));


	free(A);
	free(B);

	return 0;
}