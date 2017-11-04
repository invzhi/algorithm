#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n; // < 1000
	scanf("%d", &n);

	while (n >= 100) {
		putchar('B');
		n -= 100;
	}
	while (n >= 10) {
		putchar('S');
		n -= 10;
	}
	for (int i = 0; n >= 1; i++, n--) {
		putchar('1' + i);
	}
	return 0;
}
