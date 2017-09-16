#include <stdio.h>

int main() {
	int num, N;
	while (scanf("%d", &N) && N) {
		int sum = 0;
		while (N--) {
			scanf("%d", &num);
			sum += num;
		}
		printf("%d\n", sum);
	}
	return 0;
}