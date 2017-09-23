#include <stdio.h>

// Sample Input
// -1000000 9
// Sample Output
// -999,991

int main(int argc, char const *argv[])
{
	char str[10]; // -1000000 <= a, b <= 1000000
	int a, b, comma, n, sum;
	while (scanf("%d%d", &a, &b) == 2) {
		sum = a + b;
		if (sum < 0) {
			sum = -sum;
			printf("-");
		}
		n = sprintf(str, "%d", sum);
		comma = (n - 1) / 3;
		for (int i = 0, j = n - 3*comma; i < n; i++) {
			if (i == j) {
				j += 3;
				printf(",");
			}
			printf("%c", str[i]);
		}
	}
	return 0;
}
