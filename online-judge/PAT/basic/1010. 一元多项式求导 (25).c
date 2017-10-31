#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a, n;
	int first = 1;
	while (scanf("%d %d", &a, &n) == 2) {
		if (n != 0) {
			printf(first ? "%d %d" : " %d %d", a*n, n-1);
			first = 0;
		}
	}
	if (first) {
		printf("0 0");
	}
	return 0;
}
