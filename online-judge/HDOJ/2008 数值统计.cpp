#include <cstdio>
#include <cmath>

int main() {
	int n;
	int a, b, c;
	double num;
	while (scanf("%d", &n) == 1) {
		if (n == 0) break;
		a = b = c = 0;
		while (n--) {
			scanf("%lf", &num);
			if (num < 0) a++;
			else if (num > 0) c++;
			else b++;
		}
		printf("%d %d %d\n", a, b, c);
	}
	return 0;
}
