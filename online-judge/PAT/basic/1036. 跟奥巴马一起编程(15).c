#include <stdio.h>

void print_n_char(int n, int c) {
	for (int i = 0; i < n; i++) {
		putchar(c);
	}
}

int main(int argc, char const *argv[])
{
	int n; // 3 <= n <= 20
	char c;
	scanf("%d %c", &n, &c);

	print_n_char(n, c);
	putchar('\n');

	int numline = (n - 3) / 2;
	for (int i = 0; i < numline; i++) {
		putchar(c);
		print_n_char(n-2, ' ');
		putchar(c);
		putchar('\n');
	}

	print_n_char(n, c);
	putchar('\n');

	return 0;
}
