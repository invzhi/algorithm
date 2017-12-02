#include <stdio.h>

// Sample Input
// -1000000 9
// Sample Output
// -999,991

int main(int argc, char const *argv[])
{
	int a, b; // -1000000 <= a, b <= 1000000
	scanf("%d %d", &a, &b);

	int sum = a + b;
	if (sum < 0) {
		sum = -sum;
		putchar('-');
	}

	char str[8];
	int l = sprintf(str, "%d", sum);
	int pos = l % 3 ? l % 3 : 3;
	for (int i = 0; i < l; i++) {
		if (i == pos) {
			pos += 3;
			putchar(',');
		}
		putchar(str[i]);
	}
	return 0;
}
