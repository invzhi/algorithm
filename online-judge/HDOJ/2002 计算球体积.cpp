#include <cstdio>
#include <cmath>

#define PI 3.1415927

int main() {
	double r;
	while (scanf("%lf", &r) == 1) {
		printf("%.3f\n", PI * r * r * r * 4 / 3);
	}
	return 0;
}
