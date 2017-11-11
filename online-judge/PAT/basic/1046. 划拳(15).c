#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		int a1, b1, a2, b2;
		scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
		int sum = a1 + a2;
		if (sum != b1 && sum == b2) {
			a++;
		} else if (sum == b1 && sum != b2) {
			b++;
		}
	}

	printf("%d %d", a, b);

	return 0;
}
