#include <stdio.h>
#include <string.h>

#define N 4617

int main(int argc, char const *argv[])
{
	int n; // < 1000
	scanf("%d", &n);

	int b = n / 100;
	int s = n % 100 / 10;
	int g = n % 10;
	for (int i = 0; i < b; i++) {
		printf("B");
	}
	for (int i = 0; i < s; i++) {
		printf("S");
	}
	for (int i = 1; i <= g; i++) {
		printf("%d", i);
	}
	return 0;
}
