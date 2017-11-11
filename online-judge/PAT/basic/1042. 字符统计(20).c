#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	int cnt[128];
	memset(cnt, 0, sizeof(cnt));

	char c;
	while ((c = getchar()) != '\n' && c != EOF) {
		if (isalpha(c)) {
			cnt[tolower(c)]++;
		}
	}

	char max_c = 'a';
	for (char c = 'b'; c <= 'z'; c++) {
		if (cnt[c] > cnt[max_c]) {
			max_c = c;
		}
	}

	printf("%c %d", max_c, cnt[max_c]);

	return 0;
}
