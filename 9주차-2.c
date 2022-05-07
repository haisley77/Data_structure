#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996) 

typedef struct stack {
	char storage[1001];
	int num;
	int top;
} Stack;

void pop(Stack* ps) {
	(*ps).top--;
}

int main() {
	Stack s;
	s.top = -1;
	s.num = 0;


	char ch[1001];
	gets(ch);
	for (int i = 0; i < strlen(ch); i++) {
		if (ch[i] == '(' || ch[i] == '{' || ch[i] == '[' || ch[i] == ')' || ch[i] == '}' || ch[i] == ']') {
			s.num++;
		}
	}

	for (int i = 0; i < strlen(ch); i++) {
		if (ch[i] == '(') {
			s.storage[++s.top] = '(';
		}
		else if (ch[i] == '{') {
			s.storage[++s.top] = '{';
		}
		else if (ch[i] == '[') {
			s.storage[++s.top] = '[';
		}
		else if (ch[i] == ')') {
			if (s.storage[s.top] == '(') {
				pop(&s);
			}
			else {
				printf("Wrong_%d\n", s.num);

				break;
			}
		}
		else if (ch[i] == '}') {
			if (s.storage[s.top] == '{') {
				pop(&s);
			}
			else {
				printf("Wrong_%d\n", s.num);

				break;
			}
		}
		else if (ch[i] == ']') {
			if (s.storage[s.top] == '[') {
				pop(&s);
			}
			else {
				printf("Wrong_%d\n", s.num);

				break;
			}
		}

		if (i == strlen(ch) - 1 && s.top == -1) {
			printf("OK_%d\n", s.num);
		}
		if (i == strlen(ch) - 1 && s.top != -1) {
			printf("Wrong_%d\n", s.num);
		}
	}


	return 0;
}