#include <stdio.h>

int main() {
	int i, N, floor;
	while (scanf("%d", &N) == 1 && N) {
		int cur = 0, ans = 0;
		for (i = 0; i < N; i++) {
			scanf("%d", &floor);
			if (floor > cur) ans += 6 * (floor - cur);
			else ans += 4 * (cur - floor);
			cur = floor;
			ans += 5;
		}
		printf("%d\n", ans);
	}
	return 0;
}
