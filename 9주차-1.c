#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996) 

typedef struct stack {
	char* storage;
	int size;
	int t;
} Stack;


void push(Stack* ps, char c) {
	if ((*ps).t == (*ps).size - 1) {
		printf("Stack FULL\n");
	}
	else {
		(*ps).storage[++(*ps).t] = c;
	}
}

char pop(Stack* ps) {
	return (*ps).storage[(*ps).t--];
}

void peek(Stack* ps) {
	if ((*ps).t == -1) {
		printf("Stack Empty\n");
	}
	else {
		printf("%c\n", (*ps).storage[(*ps).t]);
	}
}
void duplicate(Stack* ps) {
	char c;
	if ((*ps).t == (*ps).size - 1) {
		printf("Stack FULL\n");
	}
	else {
		c = pop(ps);
		push(ps, c);
		push(ps, c);
	}
}

void upRotate(Stack* ps, int n) {
	char c;
	int i;
	if (n <= (*ps).t + 1) {
		c = (*ps).storage[(*ps).t];
		for (i = 0; i < n - 1; i++) {
			(*ps).storage[(*ps).t - i] = (*ps).storage[(*ps).t - i - 1];
		}
		(*ps).storage[(*ps).t - i] = c;
	}
}

void downRotate(Stack* ps, int n) {
	char c;
	int i;
	if (n <= (*ps).t + 1) {
		c = (*ps).storage[(*ps).t - n + 1];
		for (i = n - 1; i > 0; i--) {
			(*ps).storage[(*ps).t - i] = (*ps).storage[(*ps).t - i + 1];
		}
		(*ps).storage[(*ps).t - i] = c;
	}
}

void print(Stack* ps) {
	for (int i = (*ps).t; i >= 0; i--) {
		printf("%c", (*ps).storage[i]);
	}
	printf("\n");
}


int main() {
	int a;
	scanf("%d", &a);

	Stack s;
	s.size = a;
	s.t = -1;
	s.storage = (char*)malloc(sizeof(char) * s.size);

	Stack* ps = &s;

	int num, n;
	char c;
	char ch[10];


	scanf("%d", &num);
	getchar();

	for (int i = 0; i < num; i++) {
		scanf("%s", ch);
		getchar();

		if (strcmp(ch, "PUSH") == 0) {
			scanf("%c", &c);
			getchar();
			push(ps, c);
			continue;
		}
		if (strcmp(ch, "POP") == 0) {
			if (s.t == -1) {
				printf("Stack Empty\n");
			}
			else {
				pop(ps);
			}
			continue;
		}
		if (strcmp(ch, "PEEK") == 0) {
			peek(ps);
			continue;
		}
		if (strcmp(ch, "DUP") == 0) {
			duplicate(ps);
			continue;
		}
		if (strcmp(ch, "UpR") == 0) {
			scanf("%d", &n);
			getchar();
			upRotate(ps, n);
			continue;
		}
		if (strcmp(ch, "DownR") == 0) {
			scanf("%d", &n);
			getchar();
			downRotate(ps, n);
			continue;
		}
		if (strcmp(ch, "PRINT") == 0) {
			if ((*ps).t != -1) print(ps);
			continue;
		}
	}

	free(s.storage);

	return 0;
}