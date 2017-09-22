#include <stdio.h>
#include <limits.h>

int main() {
	int i, j, T, N;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		int num, begin, end;
		int mayBegin = 1;
		int thisSum = 0, maxSum = INT_MIN;
		scanf("%d", &N);
		for (j = 0; j < N; j++) {
			scanf("%d", &num);
			thisSum += num;
			if (thisSum > maxSum) {
				maxSum = thisSum;
				begin = mayBegin;
				end = j + 1;
			}
			if (thisSum < 0) {
				thisSum = 0;
				mayBegin = j + 2;
			}
		}
		printf("Case %d:\n%d %d %d\n", i + 1, maxSum, begin, end);
		if (i != T - 1) printf("\n");
	}
	return 0;
}
