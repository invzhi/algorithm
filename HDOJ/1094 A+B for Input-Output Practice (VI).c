#include <stdio.h>

int main() {
	int N;
	while (scanf("%d", &N) == 1) {
		int sum = 0;
		while (N--) {
			int num;
			scanf("%d", &num);
			sum += num;
		}
		printf("%d\n", sum);
	}
	return 0;
}