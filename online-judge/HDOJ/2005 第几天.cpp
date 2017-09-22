#include <cstdio>
#include <cmath>

int main() {
	int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int y, m, d;
	while (scanf("%d/%d/%d", &y, &m, &d) == 3) {
		int i, day = 0;
		month[2] = 28;
		if (y % 400 == 0) month[2] = 29;
		else if (y % 4 == 0 && y % 100 != 0) month[2] = 29;
		for (i = 1; i < m; i++) {
			day += month[i];
		}
		day += d;
		printf("%d\n", day);
	}
	return 0;
}
