#include <stdio.h>
#include <string.h>

#define N 1020

// str1 <- str2
void reverse(char str1[], char str2[], int n) {
	for (int i = 0, j = n-1; i < n; i++, j--) {
		str1[i] = str2[j];
	}
}

// a <- b
int add(char a[], char b[], int n) {
	int i, last = 0;
	for (i = 0; i < n || last > 0; i++) {
		int ai = a[i] ? a[i] - '0' : 0;
		int bi = b[i] ? b[i] - '0' : 0;

		int t = ai + bi + last;
		a[i] = t % 10 + '0';
		last = t / 10;
	}
	return i;
}

int ispalindromic(char str[], int n) {
	for (int i = 0, j = n-1; i < j; i++, j--) {
		if (str[i] != str[j]) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	char a[N], b[N];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	scanf("%s", a);

	int i, l = strlen(a);
	reverse(b, a, l);
	for (i = 0; i < 10 && !ispalindromic(a, l); i++) {
		printf("%s + %s = ", a, b);
		l = add(b, a, l);
		reverse(a, b, l);
		puts(a);
	}

	if (i < 10) {
		printf("%s is a palindromic number.", a);
	} else {
		puts("Not found in 10 iterations.");
	}

	return 0;
}
