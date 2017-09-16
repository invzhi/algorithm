#include <cstdio>
#include <cmath>

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		int res = 1;
		while (n--) {
			int num;
			scanf("%d", &num);
			if (num & 1) res *= num;
		}
		printf("%d\n", res);
	}
	return 0;
}