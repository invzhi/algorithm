#include <stdio.h>

int pow(int a, int n) {
	int ans = 1;
	a %= 1000;
	while (n) {
		if (n & 1) ans = ans * a % 1000;
		a = a * a % 1000;
		n >>= 1;
	}
	return ans;
}

int main() {
	int a, b;
	while (scanf("%d%d", &a, &b) == 2 && a) {
		printf("%d\n", pow(a, b));
	}
	return 0;
}
