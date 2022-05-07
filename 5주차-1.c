#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	struct node* prev;
	char elem;
	struct node* next;
} Node;

typedef struct list {
	struct node* header;
	struct node* trailer;
	int k;
} List;

void add(List* L, int r, char e) {

	if (r > (L->k + 1)) {
		printf("invalid position\n");
		return;
	}

	Node* tmp = (Node*)malloc(sizeof(Node));
	Node* p = (Node*)malloc(sizeof(Node));
	p->elem = e;
	tmp = L->header;
	for (int i = 0; i < r; i++) {
		tmp = tmp->next;
	}
	p->next = tmp;
	p->prev = tmp->prev;
	tmp->prev->next = p;
	tmp->prev = p;
	
	(L->k)++;
}
void delete(List* L, int r) {

	if (r > (L->k)) {
		printf("invalid position\n");
		return;
	}
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp = L->header;
	for (int i = 0; i < r; i++) {
		tmp = tmp->next;
	}
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	free(tmp);

	(L->k)--;
}
char get(List* L, int r) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp = L->header;
	for (int i = 0; i < r; i++) {
		tmp = tmp->next;
	}
	return tmp->elem;
}
void print(List* L) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp = L->header->next;
	while (tmp->next != NULL) {
		printf("%c", tmp->elem);
		tmp = tmp->next;
	}
	printf("\n");
}

int main() {

	List* L = (List*)malloc(sizeof(List));
	Node* h = (Node*)malloc(sizeof(Node));
	Node* t = (Node*)malloc(sizeof(Node));
	L->header = h;
	L->trailer = t;
	L->k = 0;
	h->next = t;
	h->prev = NULL;
	t->prev = h;
	t->next = NULL;

	// 리스트 L 초기화


	int n, r;
	char ch, e;
	scanf("%d", &n);
	getchar();


	for (int i = 0; i < n; i++) {
		scanf("%c", &ch);
		getchar();

		if (ch == 'A') {
			scanf("%d %c", &r, &e);
			getchar();
			add(L, r, e);
			continue;
		}
		if (ch == 'D') {
			scanf("%d", &r);
			getchar();
			delete(L, r);
			continue;
		}
		if (ch == 'G') {
			scanf("%d", &r);
			getchar();
			if (r > (L->k)) {
				printf("invalid position\n");
				continue;
			}
			else {
				printf("%c\n", get(L, r));
				continue;
			}

		}
		if (ch == 'P') {
			print(L);
			continue;
		}
		
	}

	free(L);
	free(h);
	free(t);

	return 0;
}