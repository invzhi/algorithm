#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int cnt[101];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) {
		int score;
		scanf("%d", &score);
		cnt[score]++;
	}

	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int score;
		scanf("%d", &score);
		printf(i == 0 ? "%d" : " %d", cnt[score]);
	}

	return 0;
}
