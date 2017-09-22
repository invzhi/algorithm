#include <stdio.h>

int main() {
	int n = 12;
	float sum = 0;
	while (n--) {
		float num;
		scanf("%f", &num);
		sum += num;
	}
	printf("$%.2f", sum / 12);
	return 0;
}
