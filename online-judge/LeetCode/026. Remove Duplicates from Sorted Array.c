int removeDuplicates(int* nums, int numsSize) {
	int i, j, pre;
	if (numsSize == 0) return 0;
	for (i = 1, pre = 0; i < numsSize; i++) {
		if (nums[i] != nums[pre]) {
			nums[++pre] = nums[i];
		}
	}
	return pre + 1;
}
