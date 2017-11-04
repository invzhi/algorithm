#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char c;
	int cnt[10];
	memset(cnt, 0, sizeof(cnt));
	while ((c = getchar()) != '\n' && c != EOF) {
		cnt[c-'0']++;
	}

	for (int i = 0; i < 10; i++) {
		if (cnt[i] > 0) {
			printf("%d:%d\n", i, cnt[i]);
		}
	}
	return 0;
}
