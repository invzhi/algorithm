int findNthDigit(int n) {
	int pre = 1;
	int digitType = 1;
	long digitNum = 9;
	long digitTotal = digitNum * digitType;
	while (n > digitTotal) {
		n -= (int) digitTotal;
		pre *= 10;
		digitType++;
		digitNum *= 10;
		digitTotal = digitNum * digitType;
	}
	int num = (n - 1) / digitType + pre;
	int position = digitType - 1 - (n - 1) % digitType;
	while (position--) num /= 10;
	return num % 10;
}
