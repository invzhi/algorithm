#include <stdio.h>

// 3 -> 5

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int step = 0;
	while (n != 1) {
		if (n & 1) {
			n += n/2 + 1;
		} else {
			n /= 2;
		}
		step++;
	}
	printf("%d", step);
	return 0;
}
