#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		sum += num;
	}

	printf("%d", sum*(n-1)*11);

	return 0;
}
