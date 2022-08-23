#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct stack {
	int storage[30];
	int top;
} Stack;

int isBigger(Stack A, Stack B);
Stack addBig(Stack A, Stack B, Stack C);
Stack subBig(Stack A, Stack B, Stack C);
void getBig(char ch[], Stack* S);
void putBig(Stack S);
Stack* copystack(Stack A);

int main() {

	Stack A;
	Stack B;
	Stack C;

	A.top = -1;
	B.top = -1;
	C.top = -1;

	char ch1[31], ch2[31];

	int cal_type;
	scanf("%d", &cal_type);
	getchar();

	scanf("%s", ch1);
	getchar();
	scanf("%s", ch2);
	getchar();


	getBig(ch1, &A);
	getBig(ch2, &B);


	if (cal_type == 0) {
		C = addBig(A, B, C);

		putBig(C);

	}
	else if (cal_type == 1) {

		if (isBigger(A, B) == 1) {
			C = subBig(A, B, C);

			putBig(C);
		}
		else if (isBigger(A, B) == 0) {
			C = subBig(B, A, C);

			printf("-");
			putBig(C);
		}
		else {
			printf("0");
		}

	}
	return 0;
}


int isBigger(Stack A, Stack B) {

	if (A.top > B.top) {
		return 1;
	}
	else if (A.top < B.top) {
		return 0;
	}
	else {
		for (int i = 0; i < A.top; i++) {
			if (A.storage[i] > B.storage[i]) {
				return 1;
			}
			else if (A.storage[i] < B.storage[i]) {
				return 0;
			}
			else {
				continue;
			}
		}
	}

	return -1;
}


Stack addBig(Stack A, Stack B, Stack C) {
	int tmp;
	int carry = 0;
	int t;


	while (A.top != -1 || B.top != -1) {

		if (B.top == -1) {
			tmp = A.storage[A.top] + carry;
		}
		else if (A.top == -1) {
			tmp = B.storage[B.top] + carry;
		}
		else {
			tmp = A.storage[A.top] + B.storage[B.top] + carry;
		}


		if (tmp >= 10) {
			C.storage[++C.top] = tmp % 10;

			if (A.top != -1) A.top--;
			if (B.top != -1) B.top--;
			carry = 1;
		}
		else {
			C.storage[++C.top] = tmp;

			if (A.top != -1) A.top--;
			if (B.top != -1) B.top--;
			carry = 0;
		}

	}


	if (carry == 1) {
		C.storage[++C.top] = carry;
	}

	return C;
}


Stack subBig(Stack A, Stack B, Stack C) {

	int tmp;
	int carry = 0;
	int b;


	while (A.top != -1) {

		if (B.top == -1) {
			b = 0;
		}
		else {
			b = B.storage[B.top];
		}


		tmp = A.storage[A.top] - b + carry;

		if (tmp >= 0) {

			C.storage[++C.top] = tmp;
			carry = 0;

			A.top--;
			if (B.top != -1) B.top--;
		}
		else {

			tmp += 10;

			C.storage[++C.top] = tmp;
			carry = -1;

			A.top--;
			if (B.top != -1) B.top--;

		}

	}


	return C;
}


void getBig(char ch[], Stack* S) {
	for (int i = 0; i < strlen(ch); i++) {
		S->storage[++S->top] = ch[i] - '0';
	}
}


void putBig(Stack C) {

	int n = C.top;

	while (C.storage[C.top] == 0) {
		C.top--;
	}

	for (int i = C.top; i >= 0; i--) {
		printf("%d", C.storage[i]);
	}
	return;
}


Stack* copystack(Stack A) {

	Stack* SA = (Stack*)malloc(sizeof(Stack));
	SA->top = -1;

	for (int i = A.top; i >= 0; i--) {
		SA->storage[i] = A.storage[i];
	}
	SA->top = A.top;

	return SA;
}