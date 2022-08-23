
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int sum;

typedef struct node {
	struct node* left;
	int id;
	int data;
	struct node* right;
} Node;

Node* make_the_tree(Node* root);
Node* insert(int id, int data);
Node* find_id(Node* root, int id);

void calculate(Node* tmp);


int main() {
	Node* root = (Node*)malloc(sizeof(Node));
	root = make_the_tree(root);
	Node* tree = root;

	int id;
	scanf("%d", &id);

	Node* tmp = find_id(root, id);

	if (tmp) {
		sum = 0;
		calculate(tmp);
		printf("%d",sum);
	}
	else {
		printf("-1");
	}




	free(tree);
	free(tmp);

	return 0;
}



Node* make_the_tree(Node* root) {
	root = insert(1, 20);
	root->left = insert(2, 30);
	root->right = insert(3, 50);
	root->left->left = insert(4, 70);
	root->left->right = insert(5, 90);
	root->right->right = insert(6, 120);
	root->right->right->left = insert(7, 130);
	root->right->right->right = insert(8, 80);
	return root;
}

Node* insert(int id, int data) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->id = id;
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}

Node* find_id(Node* root, int id) {
	if (root == NULL) return NULL;
	if (root->id == id) return root;

	Node* tmp = root;
	tmp = find_id(tmp->left, id);
	if (tmp) return tmp;
	return find_id(root->right, id);
}


void calculate(Node* tmp) {
	if (tmp->left != NULL && tmp->right != NULL) {
		calculate(tmp->left);
		calculate(tmp->right);
		sum += tmp->data;
	}
	else if (tmp->left != NULL && tmp->right == NULL) {
		calculate(tmp->left);
		sum += tmp->data;
	}
	else if (tmp->left == NULL && tmp->right != NULL) {
		calculate(tmp->right);
		sum += tmp->data;
	}
	else {
		sum += tmp->data;
	}
}
