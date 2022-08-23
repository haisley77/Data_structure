#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)


typedef struct stack {
	int storage[101];
	int top;
	int min[101];
} Stack;

Stack s;
Stack m;

void print(Stack s) {
	for (int i = s.top; i >= 0; i--) {
		printf("%d", s.storage[i]);
		if (i == 0) printf("\n");
		else printf(" ");
	}
	return;
}

void push(int e) {


	if (s.top < 100) {
		s.storage[++s.top] = e;
	}
	else return;

	print(s);

	if (m.top == -1) {
		m.storage[m.top + 1] = e;
		m.min[m.top + 1] = e;
		m.top++;
	}
	else {
		if (m.min[m.top] > e) {
			m.min[m.top + 1] = e;
			m.storage[m.top + 1] = e;
		}
		else {
			m.min[m.top + 1] = m.min[m.top];
			m.storage[m.top + 1] = e;
		}
		m.top++;
	}

	return;
}

void pop() {

	if (s.storage[s.top] == m.storage[m.top]) {
		m.top--;
	}

	if (s.top != -1) {
		s.top--;
	}
	else return;

	print(s);



	return;
}



void findMin() {
	printf("%d\n", m.min[m.top]);
	return;
}



int main() {


	s.top = -1;			//스택 s 초기화
	m.top = -1;


	int n, e;
	char ch;
	scanf("%d", &n);
	getchar();


	for (int i = 0; i < n; i++) {
		scanf("%c", &ch);
		getchar();

		if (ch == 'p') {
			scanf("%d", &e);
			getchar();
			push(e);
		}
		else if (ch == 'o') {
			pop();
		}
		else if (ch == 'f') {
			findMin();
		}
		else if (ch == 'q') {
			break;
		}
	}


	return 0;
}