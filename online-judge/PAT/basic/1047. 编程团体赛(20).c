#include <stdio.h>
#include <string.h>

#define N 1001

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int cnt[N];
	memset(cnt, 0, sizeof(cnt));
	
	int max_id = 0;

	for (int i = 0; i < n; i++) {
		int id, score;
		scanf("%d-%*d %d", &id, &score);
		cnt[id] += score;
		if (cnt[id] > cnt[max_id]) {
			max_id = id;
		}
	}

	printf("%d %d", max_id, cnt[max_id]);

	return 0;
}
