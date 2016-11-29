#include <stdio.h>

int pow(int a, int n) {
	int ans = 1;
	a %= 10;
	while (n) {
		if (n & 1) ans = ans * a % 10;
		a = a * a % 10;
		n >>= 1;
	}
	return ans;
}

int main() {
	int i, T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%d\n", pow(N, N));
	}
	return 0;
}