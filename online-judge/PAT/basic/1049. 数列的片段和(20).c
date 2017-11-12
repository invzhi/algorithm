#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	double sum = 0.0;
	for (int i = 0; i < n; i++) {
		double num;
		scanf("%lf", &num);
		sum += num * (i + 1) * (n - i);
	}

	printf("%.2lf", sum);

	return 0;
}
