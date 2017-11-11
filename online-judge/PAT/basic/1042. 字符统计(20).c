#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	int cnt[26];
	memset(cnt, 0, sizeof(cnt));

	char c;
	while ((c = getchar()) != '\n' && c != EOF) {
		if (isalpha(c)) {
			cnt[tolower(c)-'a']++;
		}
	}

	int max_i = 0;
	for (int i = 1; i < 26; i++) {
		if (cnt[i] > cnt[max_i]) {
			max_i = i;
		}
	}

	printf("%c %d", max_i+'a', cnt[max_i]);

	return 0;
}
