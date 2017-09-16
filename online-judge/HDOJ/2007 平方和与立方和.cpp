#include <cstdio>
#include <cmath>

int main() {
	int m, n;
	while (scanf("%d%d", &m, &n) == 2) {
		int sum1 = 0, sum2 = 0;
		if (m > n) {
			int tmp = m;
			m = n;
			n = tmp;
		}
		while (m <= n) {
			if (m & 1) sum2 += m*m*m;
			else sum1 += m*m;
			m++;
		}
		printf("%d %d\n", sum1, sum2);
	}
	return 0;
}