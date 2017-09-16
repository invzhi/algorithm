#include <cstdio>
#include <cmath>

int isNum(int num) {
	int sum = 0;
	int tmp = num;
	while (tmp) {
		int i = tmp%10;
		sum += i*i*i;
		tmp /= 10;
	}
	return sum == num;
}

int main() {
	int m, n;
	while (scanf("%d%d", &m, &n) == 2) {
		int total = 0;
		while (m <= n) {
			if (isNum(m)) {
				printf(total ? " %d" : "%d", m);
				total++;
			}
			m++;
		}
		printf(total ? "\n" : "no\n");
	}
	return 0;
}