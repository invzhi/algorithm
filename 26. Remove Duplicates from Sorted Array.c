int removeDuplicates(int* nums, int numsSize) {
	int i, j, last;
	if (numsSize == 0) return 0;
	for (i = 1, last = 0; i < numsSize; i++) {
		if (nums[i] != nums[last]) {
			nums[++last] = nums[i];
		}
	}
	return last + 1;
}