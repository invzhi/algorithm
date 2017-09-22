#include <cstdio>
#include <cmath>

int main() {
	float x1, y1, x2, y2;
	float distance;
	while (scanf("%f%f%f%f", &x1, &y1, &x2, &y2) == 4) {
		float xx = x1 - x2;
		float yy = y1 - y2;
		distance = sqrt(xx * xx + yy * yy);
		printf("%.2f\n", distance);
	}
	return 0;
}
