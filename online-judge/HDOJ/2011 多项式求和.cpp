#include <cstdio>
#include <cmath>

int main() {
	int m, n;
	while (scanf("%d", &m) == 1) {
		while (m--) {
			double sum = 0;
			scanf("%d", &n);
			for (int i = 1; i <= n; i++) {
				if (i & 1) sum += 1.0/i;
				else sum -= 1.0/i;
			}
			printf("%.2f\n", sum);
		}
	}
	return 0;
}
