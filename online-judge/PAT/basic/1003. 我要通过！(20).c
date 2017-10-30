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
		int l = strlen(s);

		int j = 0;
		while (s[j] == 'A') {
			j++;
		}

		int x = j;
		if (s[j] != 'P') {
			printf("NO\n");
			continue;
		}

		j++;
		while (s[j] == 'A') {
			j++;
		}

		if (s[j] != 'T') {
			printf("NO\n");
			continue;
		}

		int a = j - x - 1;
		if (a == 0) {
			printf("NO\n");
			continue;
		}

		x *= a;
		int yes = 1;
		for (int i = 0; i < x; i++) {
			int index = j + 1 + i;
			if (index >= l || s[index] != 'A') {
				yes = 0;
				printf("NO\n");
				break;
			}
		}
		if (yes) {
			printf("YES\n");
		}
	}
	return 0;
}
