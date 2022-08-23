#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)


char* rlsPalindrome(char A[], int l, int r) {
	if (r - l <= 0) {
		return "True";
	}
	else {
		if (A[l] == A[r]) return rlsPalindrome(A, l + 1, r - 1);
		else return "False";
	}
}

char* isPalindrome(char A[], int n) {
	return rlsPalindrome(A, 0, n - 1);
}


int main() {
	char A[101];
	gets(A);
	int n = strlen(A);

	printf("%s\n", isPalindrome(A, n));

	return 0;
}