#include <stdio.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int num;
		double sum = 0;
		scanf("%d", &num);
		for (int i = 2; i <= num; i++) sum += log10((double) i);
		printf("%d\n", (int) sum + 1);
	}
	return 0;
}