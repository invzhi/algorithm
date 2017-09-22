#include <stdio.h>

int main() {
	int T, N, num, max;
	long long sum;
	scanf("%d", &T);
	while (T--) {
		sum = max = 0;
		scanf("%d", &N);
		while (N--) {
			scanf("%d", &num);
			sum += (long long) num;
			if (num > max) max = num;
		}
		puts(sum - max >= max - 1ll ? "Yes" : "No");
	}
	return 0;
}
