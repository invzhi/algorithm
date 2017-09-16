#include <stdio.h>

int lcm(int a, int b) {
	long long mult = (long long) a * b;
	if (b) while ((a %= b) && (b %= a));
	return (int) (mult / (a + b));
}

int main() {
	int n, m, res, num;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &m);
		scanf("%d", &res);
		m--;
		while (m--) {
			scanf("%d", &num);
			res = lcm(res, num);
		}
		printf("%d\n", res);
	}
	return 0;
}