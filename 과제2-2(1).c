#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

char* isPalindrome(char A[], int n) {
	for (int i = 0; i < n / 2 - 1; i++) {
		if (A[i] == A[n - 1 - i]) continue;
		else return "False";
	}
	return "True";
}


int main() {
	char A[101];
	gets(A);
	int n = strlen(A);

	printf("%s\n", isPalindrome(A, n));

	return 0;
}