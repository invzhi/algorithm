int trap(int* height, int heightSize) {
	int left = 0, right = heightSize - 1;
	int sum = 0;
	while (left < right) {
		int min = height[left] > height[right] ? height[right] : height[left];
		if (min == height[left]) {
			while (++left < right && height[left] < min) {
				sum += min - height[left];
			}
		} else {
			while (left < --right && height[right] < min) {
				sum += min - height[right];
			}
		}
	}
	return sum;
}