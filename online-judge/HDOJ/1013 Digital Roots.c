#include <stdio.h>

char s[1000];

int main() {
	while (gets(s) && s[0] != '0') {
		int cnt = 0;
		for (int i = 0; s[i]; i++) cnt += s[i] - '0';
		while (cnt > 9) {
			int temp = 0;
			while (cnt) {
				temp += cnt % 10;
				cnt /= 10;
			}
			cnt = temp;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
