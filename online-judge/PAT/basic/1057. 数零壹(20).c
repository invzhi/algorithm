#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	char c;
	int n = 0;
	while ((c = getchar()) != '\n' && c != EOF) {
		if (isalpha(c)) {
			n += tolower(c) - 'a' + 1;
		}
	}

	int cnt[2];
	memset(cnt, 0, sizeof(cnt));
	while (n > 0) {
		cnt[n&1]++;
		n >>= 1;
	}

	printf("%d %d", cnt[0], cnt[1]);

	return 0;
}
