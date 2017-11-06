#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int n; // 0 < n <= 10^5
	scanf("%d", &n);

	int sum[n+1];
	memset(sum, 0, sizeof(sum));
	int max_id = 0, max_sum = 0;

	for (int i = 0; i < n; i++) {
		int id, score;
		scanf("%d %d", &id, &score);
		sum[id] += score;
		if (sum[id] > max_sum) {
			max_id = id;
			max_sum = sum[id];
		}
	}
	printf("%d %d", max_id, max_sum);

	return 0;
}
