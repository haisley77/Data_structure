#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct stack {
	int A[100];
	int top;
} Stack;

int isempty(Stack* S) {
	if (S->top == -1) return 1;
	else return 0;
}

void init_stack(Stack* S) {
	S->top = -1;
	for (int i = 0; i < 100; i++)
		S->A[i] = 0;
}

void enqueue(Stack* S, int e) {
	S->A[++S->top] = e;
	return;
}

int dequeue(Stack* S1, Stack* S2) {
	int e;
	if (isempty(S2) == 0) {
		e = S2->A[S2->top];
		S2->A[S2->top] = 0;
		S2->top--;
		return e;
	}
	else {
		while (isempty(S1) == 0) {
			e = S1->A[S1->top];
			S1->A[S1->top] = 0;
			S1->top--;
			enqueue(S2, e);
		}
		e = S2->A[S2->top];
		S2->A[S2->top] = 0;
		S2->top--;
	}

	return e;
}

void print(Stack* S1, Stack* S2) {

	if (S2->top != -1) {
		printf("%d\n", S2->A[S2->top]);
		return;
	}
	else {
		while (S1->top != -1) {
			enqueue(S2, S1->A[S1->top]);
			S1->top--;
		}
		printf("%d\n", S2->A[S2->top]);
		return;
	}
}




int main() {

	Stack* S1 = (Stack*)malloc(sizeof(Stack));						//rear 역할
	Stack* S2 = (Stack*)malloc(sizeof(Stack));						//front 역할

	init_stack(S1);
	init_stack(S2);

	int n, e;
	scanf("%d", &n);
	getchar();

	char ch;

	for (int i = 0; i < n; i++) {
		scanf("%c", &ch);
		getchar();

		if (ch == 'I') {
			scanf("%d", &e);
			getchar();
			enqueue(S1, e);
		}
		else if (ch == 'D') {
			printf("%d\n", dequeue(S1, S2));
		}
		else if (ch == 'F') {
			print(S1, S2);
		}
	}


	free(S1);
	free(S2);

	return 0;
}