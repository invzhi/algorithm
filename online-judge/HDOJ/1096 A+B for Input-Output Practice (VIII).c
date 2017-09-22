#include <stdio.h>

int main() {
	int M, N;
	scanf("%d", &N);
	while (N--) {
		int sum = 0;
		scanf("%d", &M); 
		while (M--) {
			int num;
			scanf("%d", &num);
			sum += num;
		}
		printf("%d\n", sum);
		if (N) printf("\n");
	}
	return 0;
}
