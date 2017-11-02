#include <stdio.h>
#include <string.h>

#define N 101

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	char s[N];
	for (int i = 0; i < n; i++) {
		scanf("%s", s);

		int cnt[3] = {0, 0, 0}; // number of 'A': before 'P', between 'P' and 'T', after 'T'
		int pos = 0, yes = 1;
		for (int j = 0; s[j] != '\0'; j++) {
			if (s[j] == 'A') {
				cnt[pos]++;
			} else if ((s[j] == 'P' && pos == 0) || (s[j] == 'T' && pos == 1)) {
				pos++;
			} else {
				yes = 0;
				break;
			}
		}

		if (yes && pos == 2 && cnt[1] != 0 && cnt[0]*cnt[1] == cnt[2]) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}
