
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)


typedef struct node {
	char elem;
	struct node* next;
} Node;

typedef struct stack {
	Node* top;
} Stack;

void init(Stack* S) {
	S->top = NULL;
	return;
}

void push(Stack* S, char sym) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->elem = sym;
	p->next = S->top;
	S->top = p;
}

char pop(Stack* S) {
	char e;
	Node* p = S->top;
	e = p->elem;
	S->top = S->top->next;
	free(p);
	return e;
}


int isoperand(char sym) {
	if (sym >= '0' && sym <= '9') return 1;
	else return 0;
}

char doOperate(char a, char b, char sym) {
	if (sym == '*') return a * b;
	else if (sym == '/') return b / a;
	else if (sym == '+') return a + b;
	else if (sym == '-') return b - a;
}



int main() {

	Stack* S = (Stack*)malloc(sizeof(Stack));
	init(S);


	char ch[101], sym, a, b;
	int n;


	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; i++) {
		scanf("%s", ch);
		getchar();

		for (int j = 0; j < strlen(ch); j++) {
			sym = ch[j];

			if (isoperand(sym)) {
				push(S, sym - '0');
			}
			else {
				a = pop(S);
				b = pop(S);
				push(S, doOperate(a, b, sym));
			}
		}

		printf("%d\n", S->top->elem);
	}

	free(S);

	return 0;
}

