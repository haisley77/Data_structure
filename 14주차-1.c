
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct node {
	struct node* left;
	int n;
	struct node* right;
} Node;

void add(Node* p, int y, int z);
Node* find_n(Node* p, int x);
Node* print(Node* p, char ch);

int main() {
	Node* root = (Node*)malloc(sizeof(Node));
	Node* p = (Node*)malloc(sizeof(Node));

	int n;
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


	int c;
	char ch[101];
	scanf("%d", &c);
	

	for (int i = 0; i < c; i++) {
		scanf("%s", ch);
		getchar();

		p = root;
		printf(" %d", p->n);


		for (int j = 0; j < strlen(ch); j++) {
			p = print(p, ch[j]);
		}
		printf("\n");
		
	}


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

Node* print(Node* p, char ch) {
	if (ch == 'R') {
		printf(" %d", p->right->n);
		return p->right;
	}
	else if (ch == 'L') {
		printf(" %d", p->left->n);
		return p->left;
	}
	return NULL;
}
