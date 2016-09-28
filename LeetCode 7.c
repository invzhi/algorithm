int reverse(int x) {
	long num = 0l;
	int sign = 1;
	if (x < 0) {
		sign = -1;
		x = -x;
	}
	while (x) {
		num = num * 10 + x % 10;
		x /= 10;
	}
	if (num > 2147483647 || num < -2147483648) return 0;
	return (int) num * sign;
}