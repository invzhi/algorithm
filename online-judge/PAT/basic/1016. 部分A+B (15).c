#include <stdio.h>

#define N 11

int p(char s[], char c) {
	int cnt = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == c) {
			cnt++;
		}
	}
	int num = 0;
	for (int i = 0; i < cnt; i++) {
		num = num*10 + (c - '0');
	}
	return num;
}

int main(int argc, char const *argv[])
{
	char a[N], b[N]; // 0 < a, b < 10^10
	char da, db;
	scanf("%s %c %s %c", a, &da, b, &db);

	int sum = p(a, da) + p(b, db);
	printf("%d", sum);
	return 0;
}
