#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int cnt[6];
	memset(cnt, 0, sizeof(cnt));

	char c;
	while ((c = getchar()) != '\n' && c != EOF) {
		switch (c) {
			case 'P':
				cnt[0]++;
				break;
			case 'A':
				cnt[1]++;
				break;
			case 'T':
				cnt[2]++;
				break;
			case 'e':
				cnt[3]++;
				break;
			case 's':
				cnt[4]++;
				break;
			case 't':
				cnt[5]++;
				break;
		}
	}

	char s[] = {'P', 'A', 'T', 'e', 's', 't'};
	
	for (int have = 1; have; ) {
		have = 0;
		for (int i = 0; i < 6; i++) {
			if (cnt[i] > 0) {
				putchar(s[i]);
				have = 1;
				cnt[i]--;
			}
		}
	}

	return 0;
}
