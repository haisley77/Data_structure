
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct node {
	struct node* left;
	int id;
	int data;
	struct node* right;
} Node;

Node* make_the_tree(Node* root);
Node* insert(int id, int data);
Node* find_id(Node* root, int id);
void pretranverse(Node* tmp);
void midtranverse(Node* tmp);
void posttranverse(Node* tmp);


int main() {
	Node* root = (Node*)malloc(sizeof(Node));
	root = make_the_tree(root);
	Node* tree = root;
	
	int n, id;
	scanf("%d%d", &n, &id);

	Node* tmp = find_id(root, id);

	if (tmp) {
		if (n == 1) {
			pretranverse(tmp);
		}
		else if (n == 2) {
			midtranverse(tmp);
		}
		else if (n == 3) {
			posttranverse(tmp);
		}
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
	root->right=insert(3, 50);
	root->left->left=insert(4, 70);
	root->left->right=insert(5, 90);
	root->right->right=insert( 6, 120);
	root->right->right->left=insert(7, 130);
	root->right->right->right=insert(8, 80);
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

void pretranverse(Node* tmp) {
	if (tmp->left != NULL && tmp->right!=NULL) {
		printf(" %d", tmp->data);
		pretranverse(tmp->left);
		pretranverse(tmp->right);
	}
	else if (tmp->left != NULL && tmp->right == NULL) {
		printf(" %d", tmp->data);
		pretranverse(tmp->left);
	}
	else if (tmp->left == NULL && tmp->right != NULL) {
		printf(" %d", tmp->data);
		pretranverse(tmp->right);
	}
	else {
		printf(" %d", tmp->data);
	}
}

void midtranverse(Node* tmp) {
	if (tmp->left != NULL && tmp->right != NULL) {
		midtranverse(tmp->left);
		printf(" %d", tmp->data);
		midtranverse(tmp->right);
	}
	else if (tmp->left != NULL && tmp->right == NULL) {
		midtranverse(tmp->left);
		printf(" %d", tmp->data);
	}
	else if (tmp->left == NULL && tmp->right != NULL) {
		printf(" %d", tmp->data);
		midtranverse(tmp->right);
	}
	else {
		printf(" %d", tmp->data);
	}
}
void posttranverse(Node* tmp) {
	if (tmp->left != NULL && tmp->right != NULL) {
		posttranverse(tmp->left);
		posttranverse(tmp->right);
		printf(" %d", tmp->data);
	}
	else if (tmp->left != NULL && tmp->right == NULL) {
		posttranverse(tmp->left);
		printf(" %d", tmp->data);
	}
	else if (tmp->left == NULL && tmp->right != NULL) {
		
		posttranverse(tmp->right);
		printf(" %d", tmp->data);
	}
	else {
		printf(" %d", tmp->data);
	}
}
