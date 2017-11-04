#include <stdio.h>

#define N 10

int main(int argc, char const *argv[])
{
	int cnt[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &cnt[i]);
	}

	int notzero = 0;
	while (cnt[++notzero] == 0);

	cnt[notzero]--;
	putchar(notzero + '0');
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			putchar(i + '0');
		}
	}
	return 0;
}
