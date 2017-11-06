#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 81

int main(int argc, char const *argv[])
{
	char input[N], output[N];
	scanf("%s %s", input, output);

	int cnt[128];
	memset(cnt, 0, sizeof(cnt));

	for (int i = 0, j = 0; input[i]; i++) {
		if (input[i] != output[j]) {
			char c = toupper(input[i]);
			if (cnt[c] == 0) {
				putchar(c);
				cnt[c]++;
			}
		} else {
			j++;
		}
	}
	return 0;
}
