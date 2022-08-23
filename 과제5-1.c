#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int sum = 0;
int depth = 0;

typedef struct node {
	struct node* left;
	int n;
	struct node* right;
} Node;

void add(Node* p, int y, int z);
Node* find_n(Node* p, int x);
Node* print(Node* p, char ch);
int pathLength(Node* root);

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

	printf("%d", pathLength(root));


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

int pathLength(Node* root) {

	if (root->left == NULL && root->right == NULL) {
		sum += depth;
		depth--;
	}
	else if (root->left == NULL) {
		depth++;

		pathLength(root->right);
		sum += depth;
		depth--;
	}
	else if (root->right == NULL) {
		depth++;
		pathLength(root->left);
		sum += depth;
		depth--;
	}
	else {
		depth++;
		pathLength(root->left);
		depth++;
		pathLength(root->right);
		sum += depth;
		depth--;

	}
	return sum;

}