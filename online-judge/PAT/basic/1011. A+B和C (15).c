#include <stdio.h>

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);

	long a, b, c;
	for (int i = 1; i <= t; i++) {
		scanf("%ld %ld %ld", &a, &b, &c);
		printf("Case #%d: %s\n", i, a + b > c ? "true" : "false");
	}
	return 0;
}
