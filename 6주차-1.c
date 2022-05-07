#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int coef;
	int exp;
	struct node* next;
} Node;

typedef struct list {
	struct node* header;
	struct node* k;
} List;

List* init_(List* L) {

	Node* h = (Node*)malloc(sizeof(Node));
	h->next = NULL;
	L->header = h;
	L->k = h;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		Node* p = (Node*)malloc(sizeof(Node));
		scanf("%d%d", &(p->coef), &(p->exp));
		p->next = NULL;
		L->k->next = p;
		L->k = p;
	}

	return L;
}

void appendTerm(Node** k, int c, int e) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->coef = c;
	tmp->exp = e;
	tmp->next = NULL;
	(*k)->next = tmp;
	(*k) = tmp;
	return;
}

Node* addPoly(Node* A, Node* B) {
	Node* res = (Node*)malloc(sizeof(Node));
	res->next = NULL;
	Node* k = (Node*)malloc(sizeof(Node));

	A = A->next;
	B = B->next;
	k = res;
	int sum;

	while ((A != NULL) && (B != NULL)) {
		if (A->exp > B->exp) {
			appendTerm(&k, A->coef, A->exp);
			A = A->next;
		}
		else if (A->exp < B->exp) {
			appendTerm(&k, B->coef, B->exp);
			B = B->next;
		}
		else {
			sum = A->coef + B->coef;
			if (sum != 0) {
				appendTerm(&k, sum, A->exp);
			}
			A = A->next;
			B = B->next;
		}
	}
	while (A != NULL) {
		appendTerm(&k, A->coef, A->exp);
		A = A->next;
	}
	while (B != NULL) {
		appendTerm(&k, B->coef, B->exp);
		B = B->next;
	}

	free(k);

	return res;
}

int main() {

	List* A = (List*)malloc(sizeof(List));
	List* B = (List*)malloc(sizeof(List));

	A = init_(A);
	B = init_(B);
	// 다항식 A, B 리스트 입력


	Node* p = (Node*)malloc(sizeof(Node));
	p = addPoly(A->header, B->header);
	p = p->next;
	while (p != NULL) {
		printf(" %d %d", p->coef, p->exp);
		p = p->next;
	}

	free(A);
	free(B);
	free(p);

	return 0;
}