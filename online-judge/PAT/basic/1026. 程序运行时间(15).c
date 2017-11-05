#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c1, c2; // 0 <= c1 < c2 <= 10^7
	scanf("%d %d", &c1, &c2);

	int second = (c2 - c1 + 50) / 100; // rounding
	printf("%02d:%02d:%02d", second/3600, second/60%60, second%60);
	return 0;
}
