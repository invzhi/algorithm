#include <stdio.h>

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		int sum;
		if (n & 1) sum = (n + 1) / 2 * n;
		else sum = n / 2 * (n + 1);
		printf("%d\n\n", sum);
	}
	return 0;
}