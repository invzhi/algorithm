#include <cstdio>
#include <cmath>

int main() {
	double num;
	while (scanf("%lf", &num) == 1) {
		printf("%.2f\n", num < 0 ? -num : num);
	}
	return 0;
}
