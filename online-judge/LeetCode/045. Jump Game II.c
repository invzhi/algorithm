int jump(int* nums, int numsSize) {
	int i, end, nextEnd, cnt;
	end = nextEnd = cnt = 0;
	for (i = 0; i < numsSize - 1; i++) {
		if (i > end) {
			cnt = -1;
			break;
		}
		if (i + nums[i] > nextEnd) nextEnd = i + nums[i];
		if (i == end) {
			end = nextEnd;
			cnt++;
		}
	}
	return cnt;
}
