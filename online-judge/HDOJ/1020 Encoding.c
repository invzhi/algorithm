#include <stdio.h>

char s[10000];

int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		int i;
		int length = 1;
		scanf("%s", s);
		for (i = 1; s[i - 1]; i++) {
			if (s[i] == 0 || s[i] != s[i - 1]) {
				if (length == 1) printf("%c", s[i - 1]);
				else printf("%d%c", length, s[i - 1]);
				length = 1;
			} else length++;
		}
		printf("\n");
	}
	return 0;
}