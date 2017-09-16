#include <cstdio>
#include <cmath>

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		m--;
		double sum = n;
		double num = n;
		while (m--) {
			num = sqrt(num);
			sum += num;
		}
		printf("%.2f\n", sum);
	}
	return 0;
}