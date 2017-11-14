#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	double r1, p1, r2, p2;
	scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);

	double a = r1 * r2 * cos(p1+p2);
	double b = r1 * r2 * sin(p1+p2);

	// should not output -0.00
	if (a < 0 && a > -0.005) {
		a = 0;
	}
	if (b < 0 && b > -0.005) {
		b = 0;
	}

	printf("%.2lf%+.2lfi", a, b);
	return 0;
}
