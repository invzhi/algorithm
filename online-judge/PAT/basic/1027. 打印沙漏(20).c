#include <stdio.h>

void print_line(char c, int space, int n) {
	for (int i = 0; i < space; i++) {
		putchar(' ');
	}
	for (int i = 0; i < n; i++) {
		putchar(c);
	}
	putchar('\n');
}

int main(int argc, char const *argv[])
{
	int n; // 0 < n <= 1000
	char c;
	scanf("%d %c", &n, &c);

	n -= 1;
	int max;
	for (max = 3; n >= 2*max; max += 2) {
		n -= 2 * max;
	}
	max -= 2;

	int space = 0;
	for (int num = max; num > 1; num -= 2) {
		print_line(c, space, num);
		space++;
	}
	for (int num = 1; num <= max; num += 2) {
		print_line(c, space, num);
		space--;
	}
	printf("%d", n);
	return 0;
}
