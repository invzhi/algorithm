#include <stdio.h>
#include <string.h>

#define N 101

int main(int argc, char const *argv[])
{
	int k; // < 100
	scanf("%d", &k);

	char mark[N];
	memset(mark, 0, sizeof(mark));
	for (int i = 0; i < k; i++) {
		int n; // 1 < n <= 100
		scanf("%d", &n);
		mark[n] = 1;
	}

	for (int i = 2; i < N; i++) {
		if (mark[i] == 1) {
			int n = i;
			while (n != 1) {
				if (n & 1) {
					n += n/2 + 1; // n = (3*n + 1) / 2
				} else {
					n /= 2;
				}
				if (n < N) {
					if (mark[n] != -1) {
						mark[n] = -1;
					} else {
						break;
					}
				}
			}
		}
	}

	int i = N - 1;
	while (mark[i] != 1) {
		i--;
	}
	printf("%d", i);

	for (i = i - 1; i > 1; i--) {
		if (mark[i] == 1) {
			printf(" %d", i);
		}
	}
	return 0;
}
