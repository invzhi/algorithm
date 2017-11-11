#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int cnt[128];
	memset(cnt, 0, sizeof(cnt));

	char c;
	while ((c = getchar()) != '\n') {
		cnt[c]++;
	}

	int yes = 1, n = 0;
	while ((c = getchar()) != '\n' && c != EOF) {
		if (cnt[c] > 0) {
			cnt[c]--;
		} else {
			yes = 0;
			n++;
		}
	}

	if (yes) {
		for (int i = 0; i < 128; i++) {
			n += cnt[i];
		}
		printf("Yes %d", n);
	} else {
		printf("No %d", n);
	}

	return 0;
}
