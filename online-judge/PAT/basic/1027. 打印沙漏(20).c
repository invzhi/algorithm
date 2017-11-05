#include <stdio.h>
#include <stdlib.h>

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

	int h;
	for (h = 1; ; h++) {
		if (n < 2*h*h-1) { // 2*h*h-1 = 1, 6, 10, 14, ...
			h--;
			n -= 2*h*h-1;
			break;
		}
	}

	int mid = h - 1, cnt = 2*h - 1;
	for (int i = 0; i < cnt; i++) {
		int dis = abs(mid-i);
		print_line(c, mid-dis, 2*dis+1);
	}
	printf("%d", n);
	return 0;
}
