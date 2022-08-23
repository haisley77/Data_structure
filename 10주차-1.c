
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


typedef struct nodetype {
	char data;						//연산자 저장하는 변수
	int n;							//연산자의 우선순위를 저장하는 변수
	struct nodetype* link;			//연결된 노드를 가리키는 변수
} Nodetype;

typedef struct stacktype {
	Nodetype* top;
} Stacktype;

void init_stack(Stacktype* s) {
	s->top = NULL;
}

int isOperand(char sym) {
	if (sym == '(' || sym == ')' || sym == '*' || sym == '/' || sym == '+' || sym == '-' || sym == '>' || sym == '<' || sym == '&' || sym == '|') return 0;
	else return 1;
}

int prec(char op, char ch[], int num) {

	if (op == '*' || op == '/') {
		return 5;
	}
	else if (op == '!') {
		return 6;
	}
	else if (op == '>' || op == '<') {
		return 3;
	}
	else if (op == '&') {
		return 2;
	}
	else if (op == '|') {
		return 1;
	}
	else if (op == '+' || op == '-') {
		if (num == 0) {
			return 6;
		}
		else if (isOperand(ch[num - 1]) == 0 && ch[num - 1] != ')') {
			return 6;
		}
		else {
			return 4;
		}
	}
	else return -1;
}


void push(Stacktype* s, char elem, int x) {
	Nodetype* temp = (Nodetype*)malloc(sizeof(Nodetype));
	temp->data = elem;
	temp->n = x;							//미리 계산된 elem의 우선순위 x를 temp 노드의 n값에 저장
	temp->link = s->top;
	s->top = temp;
}

char pop(Stacktype* s) {
	Nodetype* temp = (Nodetype*)malloc(sizeof(Nodetype));
	temp = s->top;
	char e = s->top->data;
	s->top = temp->link;

	free(temp);
	return e;
}



int main() {
	Stacktype s;
	init_stack(&s);
	Stacktype* ps;
	ps = &s;

	int n, num;
	scanf("%d", &n);
	getchar();

	char ch[101], sym;

	for (int i = 0; i < n; i++) {
		num = 0;
		scanf("%s", ch);
		getchar();

		while (ch[num] != '\0') {
			sym = ch[num];
			if (sym == '(') {
				push(ps, sym, prec(sym, ch, num));
				num++;
			}
			else if (sym == ')') {
				while (ps->top->data != '(') {
					printf("%c", pop(ps));
				}
				pop(&s);
				num++;
			}

			else if (sym == '*' || sym == '/' || sym == '>' || sym == '<' || sym == '+' || sym == '-' || sym == '!') {
				while (ps->top != NULL && ps->top->data != '(' && (ps->top->n >= prec(sym, ch, num))) {
					printf("%c", pop(ps));
				}
				push(ps, sym, prec(sym, ch, num));
				num++;
			}
			else if (sym == '&' || sym == '|') {
				while (ps->top != NULL && ps->top->data != '(' && (ps->top->n >= prec(sym, ch, num))) {
					printf("%c", pop(ps));
				}
				push(ps, sym, prec(sym, ch, num));
				push(ps, sym, prec(sym, ch, num));
				num += 2;
			}
			else if (isOperand(sym) == 1) {
				printf("%c", sym);
				num++;
			}

		}

		while (ps->top != NULL) {
			printf("%c", pop(ps));
		}
		printf("\n");

	}
	


	return;
}


//연결리스트 이용한 방법


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct stack {
	char storage[100];
	int pre[100];
	int top;
} Stack;

void initstack(Stack* S) {
	S->top = -1;
}

void push(Stack* S, char sym) {
	S->storage[++S->top] = sym;
}

char pop(Stack* S) {
	return S->storage[S->top--];
}

int isoperand(char sym) {
	if (sym=='(' || sym==')' || sym == '!' || sym == '+' || sym == '-' || sym == '*' || sym == '/' || sym == '>' || sym == '<' || sym == '&' || sym == '|') return 0;
	else return 1;
}				//피연산자

int preorder(char ch[], char sym, int n) {
	if (sym == '!') return 6;
	else if (sym == '*' || sym == '/') return 5;
	else if (sym == '>' || sym == '<') return 3;
	else if (sym == '&') return 2;
	else if (sym == '|') return 1;
	else if (sym == '+' || sym == '-') {
		if (n == -1) return 6;
		else if (isoperand(ch[n])==0 && ch[n]!=')') return 6;
		else return 4;
	}
	return 0;
}



int main() {

	Stack* S = (Stack*)malloc(sizeof(Stack));
	initstack(S);


	int n;
	scanf("%d", &n);
	getchar();

	char ch[101], sym;

	for (int i = 0; i < n; i++) {
		scanf("%s", ch);
		getchar();

		for (int j = 0; j < strlen(ch); j++) {
			sym = ch[j];

			if (sym == '(') {
				push(S, sym);		//'('연산자 push
				S->pre[S->top] = j - 1;
			}
			else if (sym == ')') {
				while (S->storage[S->top] != '(' && S->top != -1) {
					printf("%c", pop(S));
				}
				pop(S);				//'('연산자 pop
			}
			else if (sym == '!' || sym == '+' || sym == '-' || sym == '*' || sym == '/' || sym == '>' || sym == '<') {
				while (preorder(ch, sym, j - 1) <= preorder(ch, S->storage[S->top], S->pre[S->top]) && S->top != -1) {
					printf("%c", pop(S));
				}
				push(S, sym);
				S->pre[S->top] = j - 1;
			}
			else if (sym == '&' || sym == '|') {
				while (preorder(ch, sym, j - 1) <= preorder(ch, S->storage[S->top], S->pre[S->top]) && S->top != -1) {
					printf("%c", pop(S));
				}
				push(S, sym);
				S->pre[S->top] = j - 1;
				push(S, sym);
				S->pre[S->top] = j;
				j++;
			}
			else if (isoperand(sym)==1) {
				printf("%c", sym);
			}

		}

		while (S->top != -1) {
			printf("%c", pop(S));
		}
		printf("\n");
	}

	return 0;
}
*/


//배열 이용한 방법