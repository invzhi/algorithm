#include <stdio.h>

int main() {
	int a, b, mult;
	while (scanf("%d%d", &a, &b) == 2) {
		mult = a * b;
		if (b) while ((a %= b) && (b %= a));
		printf("%d\n", mult / (a + b));
	}
	return 0;
}