#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a, b, d; // 0 <= a, b < 2^30 -1  1 < d <= 10
	scanf("%d %d %d", &a, &b, &d);

	int sum = a + b; // 0 <= sum < 2^31 - 2
	char num[31];

	int i = 0;
	for (i = 0; sum > 0; i++) {
		num[i] = sum % d + '0';
		sum /= d;
	}

	if (i == 0) {
		putchar('0');
	}
	for (i = i - 1; i >= 0; i--) {
		putchar(num[i]);
	}
	return 0;
}
