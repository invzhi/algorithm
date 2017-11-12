#include <stdio.h>
#include <string.h>

#define N 101

char turn1(char a, char b) {
	int num = ((b-'0') + (a-'0')) % 13;
	char encrypt[] = "0123456789JQK";
	return encrypt[num];
}

char turn2(char a, char b) {
	int num = b - a;
	if (num < 0) {
		num += 10;
	}
	return num + '0';
}

int main(int argc, char const *argv[])
{
	char a[N], b[N];
	scanf("%s %s", a, b);

	int al = strlen(a);
	int bl = strlen(b);

	int maxl = al > bl ? al : bl;

	if (al > bl) {
		int d = al - bl;
		for (int i = bl; i >= 0; i--) {
			b[i+d] = b[i];
		}
		for (int i = 0; i < d; i++) {
			b[i] = '0';
		}
	} else if (al < bl) {
		int d = bl - al;
		for (int i = al; i >= 0; i--) {
			a[i+d] = a[i];
		}
		for (int i = 0; i < d; i++) {
			a[i] = '0';
		}
	}

	for (int i = 1; i <= maxl; i++) {
		int j = maxl - i;
		if (i & 1) {
			b[j] = turn1(a[j], b[j]);
		} else {
			b[j] = turn2(a[j], b[j]);
		}
	}

	printf("%s", b);

	return 0;
}
