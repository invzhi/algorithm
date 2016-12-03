#include <stdio.h>
#include <string.h>

#define MAXN 1005

char a[MAXN], b[MAXN], c[MAXN];

void reverse(char* s, int n) {
	int i;
	char temp[MAXN];
	strcpy(temp, s);
	for (i = 0; i < MAXN; i++) {
		if (i < n) s[i] = temp[n - 1 - i];
		else s[i] = 0;
	}
}

void sum() {
	int aL = strlen(a);
	int bL = strlen(b);
	reverse(a, aL);
	reverse(b, bL);
	int i;
	int max = aL > bL ? aL : bL;
	int min = aL < bL ? aL : bL;
	for (i = 0; i < max; i++) {
		if (i < min) c[i] = a[i] - '0' + b[i];
		else c[i] = a[i] + b[i];
	}
	c[i] = 0;
	int pre = 0;
	for (i = 0; i < max; i++) {
		c[i] += pre;
		if (c[i] > '9') {
			c[i] -= 10;
			pre = 1;
		} else pre = 0;
	}
	if (pre) {
		c[i++] = '1';
		c[i] = 0;
		max++;
	}
	reverse(c, max);
}

int main() {
	int i, T;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%s%s", a, b);
		printf("Case %d:\n%s + %s = ", i + 1, a, b);
		sum();
		printf("%s\n", c);
		if (i != T - 1) printf("\n");
	}
	return 0;
}