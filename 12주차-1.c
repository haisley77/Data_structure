#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct treenode {
	struct treenode* left;
	int data;
	struct treenode* right;
} Treenode;


typedef struct tree {
	Treenode* root;
} Tree;

Treenode* insert(Treenode* left, int data, Treenode* right) {
	Treenode* tmp = (Treenode*)malloc(sizeof(Treenode));
	tmp->left = left;
	tmp->right = right;
	tmp->data = data;

	return tmp;
}

void print(Treenode* p) {
	printf("%d", p->data);
	if (p->left != NULL) {
		printf(" ");
		printf("%d", p->left->data);
	}

	if (p->right != NULL) {
		printf(" ");
		printf("%d", p->right->data);
	}
}

int main() {

	Treenode* F7 = insert(NULL, 130, NULL);
	Treenode* F8 = insert(NULL, 80, NULL);
	Treenode* F6 = insert(F7, 120, F8);
	Treenode* F3 = insert(NULL, 50, F6);
	Treenode* F4 = insert(NULL, 70, NULL);
	Treenode* F5 = insert(NULL, 90, NULL);
	Treenode* F2 = insert(F4, 30, F5);
	Treenode* F1 = insert(F2, 20, F3);


	int n;
	scanf("%d", &n);

	if (n == 1) {
		print(F1);
	}
	else if (n == 2) {
		print(F2);
	}
	else if (n == 3) {
		print(F3);
	}
	else if (n == 4) {
		print(F4);
	}
	else if (n == 5) {
		print(F5);
	}
	else if (n == 6) {
		print(F6);
	}
	else if (n == 7) {
		print(F7);
	}
	else if (n == 8) {
		print(F8);
	}
	else {
		printf("-1");
	}



	return 0;
}