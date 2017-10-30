#include <stdio.h>
#include <string.h>

#define N 4617

int main(int argc, char const *argv[])
{
	int k;
	scanf("%d", &k);

	char num[N];
	memset(num, 0, sizeof(num));
	for (int i = 0; i < k; i++) {
		int n;
		scanf("%d", &n);

		num[n]++;
		while (n != 1) {
			if (n & 1) {
				n += n/2 + 1;
			} else {
				n /= 2;
			}
			num[n]--;
		}
	}

	int first = 1;
	for (int i = N - 1; i > 1; i--) {
		if (num[i] == 1) {
			printf(first ? "%d" : " %d", i);
			first = 0;
		}
	}
	return 0;
}
