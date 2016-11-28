#include <stdio.h>

int main() {
	int a, b, mult, temp;
	while (scanf("%d%d", &a, &b) == 2) {
		mult = a * b;
		while (b) {
			temp = a % b;
			a = b;
			b = temp;
		}
		printf("%d\n", mult / a);
	}
	return 0;
}