int jump(int* nums, int numsSize) {
	int end, nextEnd, cnt, i;
	end = nextEnd = cnt = 0;
	numsSize--;
	for (i = 0; i < numsSize; i++) {
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