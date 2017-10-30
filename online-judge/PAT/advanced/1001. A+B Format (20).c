#include <stdio.h>

// Sample Input
// -1000000 9
// Sample Output
// -999,991

int main(int argc, char const *argv[])
{
	char str[10]; // -1000000 <= a, b <= 1000000
	int a, b, sum;
	scanf("%d%d", &a, &b);
	sum = a + b;
	if (sum < 0) {
		sum = -sum;
		printf("-");
	}

	int l = sprintf(str, "%d", sum);
	int n = (l - 1) / 3;
	int position = l - 3*n;
	for (int i = 0; i < l; i++) {
		if (i == position) {
			position += 3;
			printf(",");
		}
		printf("%c", str[i]);
	}
	return 0;
}
