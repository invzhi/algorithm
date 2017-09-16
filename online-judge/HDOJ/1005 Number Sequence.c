#include <stdio.h>

int main() {
	int i;
	int A, B, n;
	int f[49] = {1, 1};
	while (scanf("%d%d%d", &A, &B, &n) && (A || B || n)) {
		for (i = 2; i < 49; i++) {
			f[i] = (f[i - 1] * A + f[i - 2] * B) % 7;
		}
		printf("%d\n", f[(n - 1) % 49]);
	}
	return 0;
}