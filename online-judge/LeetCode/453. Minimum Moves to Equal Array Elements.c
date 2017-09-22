int minMoves(int* nums, int numsSize) {
	int i;
	int cnt = 0;
	int min = nums[0];
	for (i = 1; i < numsSize; i++) {
		if (nums[i] < min) {
			cnt += i * (min - nums[i]);
			min = nums[i];
		} else cnt += nums[i] - min;
	}
	return cnt;
}
