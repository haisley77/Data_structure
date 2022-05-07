#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


typedef struct node {
	int elem;
	struct node* next;
} Node;



Node* init_(void) {
	Node* header = (Node*)malloc(sizeof(Node));		
	Node* h = (Node*)malloc(sizeof(Node));
	header = h;
	h->next = NULL;

	int n, num;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		Node* p = (Node*)malloc(sizeof(Node));
		scanf("%d", &num);
		p->elem = num;
		p->next = NULL;			

		h->next = p;			
		h = p;					
	}

	return header;
}

void addLast(Node** k, int e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->elem = e;
	p->next = NULL;
	(*k)->next = p;
	(*k) = p;
}


Node* union_(Node* A, Node* B) {
	Node* a = (Node*)malloc(sizeof(Node));
	Node* b = (Node*)malloc(sizeof(Node));
	Node* c = (Node*)malloc(sizeof(Node));
	Node* k = (Node*)malloc(sizeof(Node));
	a = A->next;
	b = B->next;
	c->next = NULL;
	k = c;
	if (a == NULL && b == NULL) {
		k->next = NULL;
		return c;
	}
	
	while (a != NULL && b != NULL) {
		if (a->elem < b->elem) {
			addLast(&k, a->elem);
			a = a->next;
		}
		else if (a->elem > b->elem) {
			addLast(&k, b->elem);
			b = b->next;
		}
		else {
			addLast(&k, a->elem);
			a = a->next;
			b = b->next;
		}
	}
	while (a != NULL) {
		addLast(&k, a->elem);
		a = a->next;
	}
	while (b != NULL) {
		addLast(&k, b->elem);
		b = b->next;
	}

	return c;
}

Node* intersect_(Node* A, Node* B) {
	Node* a = (Node*)malloc(sizeof(Node));
	Node* b = (Node*)malloc(sizeof(Node));
	Node* c = (Node*)malloc(sizeof(Node));
	Node* k = (Node*)malloc(sizeof(Node));
	a = A->next;
	b = B->next;
	c->next = NULL;
	k = c;
	

	if (a == NULL || b == NULL) {
		k->next = NULL;
		return c;
	}

	while (a != NULL && b != NULL) {
		if (a->elem < b->elem) {
			a = a->next;
		}
		else if (a->elem > b->elem) {
			b = b->next;
		}
		else {
			addLast(&k, a->elem);
			a = a->next;
			b = b->next;
		}
	}

	return c;
}

void print_(Node* C) {
	Node* p = (Node*)malloc(sizeof(Node));
	p = C->next;
	if (p == NULL) {
		printf(" 0\n");
	}
	else {
		while (p != NULL) {
			printf(" %d", p->elem);
			p = p->next;
		}
		printf("\n");
	}

}

int main() {
	Node* A = (Node*)malloc(sizeof(Node));
	Node* B = (Node*)malloc(sizeof(Node));
	Node* C = (Node*)malloc(sizeof(Node));
	
	C->next = NULL;

	A = init_();
	B = init_();

	C = union_(A, B);
	print_(C);
	C = intersect_(A, B);
	print_(C);

	free(A);
	free(B);
	free(C);

	return 0;
}