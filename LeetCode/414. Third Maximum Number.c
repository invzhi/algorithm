int thirdMax(int* nums, int numsSize) {
	int i;
	int a, b, c;
	int sign2, sign3;
	a = nums[0];
	b = c = INT_MIN;
	sign2 = sign3 = 0;
	for (i = 1; i < numsSize; i++) {
		if (nums[i] > a) {
			c = b;
			b = a;
			a = nums[i];
			if (sign2) sign3 = 1;
			else sign2 = 1;
		} else if (nums[i] < a && nums[i] > b || !sign2 && nums[i] == INT_MIN && a != INT_MIN) {
			c = b;
			b = nums[i];
			if (sign2) sign3 = 1;
			else sign2 = 1;
		} else if (nums[i] < b && nums[i] > c || !sign3 && nums[i] == INT_MIN && b != INT_MIN) {
			c = nums[i];
			sign3 = 1;
		}
	}
	return sign3 ? c : a;
}