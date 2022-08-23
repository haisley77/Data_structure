#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


typedef struct node {
	struct node* left;
	int n;
	struct node* right;
} Node;

typedef struct record {
	Node* p;
	struct record* next;
} Record;


typedef struct stack {
	Record* top;
} Stack;

void add(Node* p, int y, int z);
Node* find_n(Node* p, int x);
Node* print(Node* p, char ch);
void binaryInOrder(Node* root);
void push(Stack* S, Node* p);
Node* pop(Stack* S);

int n;

int main() {
	Node* root = (Node*)malloc(sizeof(Node));
	Node* p = (Node*)malloc(sizeof(Node));


	scanf("%d", &n);
	getchar();

	int x, y, z;

	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		getchar();

		if (i == 0) {
			root->n = x;
			add(root, y, z);
			p = root;
		}
		else {
			p = find_n(p, x);
			if (p == NULL) {
				p = root;
				p = find_n(p, x);
			}
			add(p, y, z);
		}
	}

	//트리 생성

	binaryInOrder(root);

	free(p);
	free(root);

	return 0;
}

void add(Node* p, int y, int z) {
	if (y != 0) {
		Node* L = (Node*)malloc(sizeof(Node));
		L->left = NULL;
		L->right = NULL;
		L->n = y;
		p->left = L;
	}
	else p->left = NULL;

	if (z != 0) {
		Node* R = (Node*)malloc(sizeof(Node));
		R->left = NULL;
		R->right = NULL;
		R->n = z;
		p->right = R;
	}
	else p->right = NULL;
}

Node* find_n(Node* p, int x) {
	Node* tmp = p;

	if (p == NULL) return NULL;
	if (p->n == x) return p;

	tmp = find_n(tmp->left, x);
	if (tmp) return tmp;
	return find_n(p->right, x);
}

void push(Stack* S, Node* p) {
	Record* tmp = (Record*)malloc(sizeof(Record));
	tmp->p = p;
	tmp->next = S->top;
	S->top = tmp;
}
Node* pop(Stack* S) {
	Record* tmp = S->top;
	S->top = S->top->next;
	return tmp->p;
}

void binaryInOrder(Node* root) {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;

	Node* index = root;

	while (1) {
		while (index != NULL) {
			push(S, index);
			index = index->left;
		}

		if (S->top != NULL) {
			index = pop(S);
			printf("%d ", index->n);
			index = index->right;

		}
		else {
			break;
		}

	}

	return;
}