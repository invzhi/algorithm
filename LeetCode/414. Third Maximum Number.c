int thirdMax(int* nums, int numsSize) {
	int i;
	long a, b, c;
	a = b = c = LONG_MIN;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] > a) {
			c = b;
			b = a;
			a = nums[i];
		} else if (nums[i] < a && nums[i] > b) {
			c = b;
			b = nums[i];
		} else if (nums[i] < b && nums[i] > c) {
			c = nums[i];
		}
	}
	return c == LONG_MIN ? a : c;
}