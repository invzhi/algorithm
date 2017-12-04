#include <stdio.h>

int main(int argc, char const *argv[])
{
	int k;
	scanf("%d", &k);

	int num[k];
	int left_i = 0, right_i = k - 1, temp_i = 0;
	int max_sum = -1, sum = 0;

	for (int i = 0; i < k; i++) {
		scanf("%d", &num[i]);
		sum += num[i];
		if (sum < 0) {
			sum = 0;
			temp_i = i + 1;
		} else if (sum > max_sum) {
			max_sum = sum;
			left_i = temp_i;
			right_i = i;
		}
	}

	printf("%d %d %d", max_sum < 0 ? 0 : max_sum, num[left_i], num[right_i]);

	return 0;
}
