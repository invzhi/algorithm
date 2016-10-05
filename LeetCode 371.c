int getSum(int a, int b) {
	int temp;
	while (a) {
		temp = a ^ b;
		a = (a & b) << 1;
		b = temp;
	}
	return b;
}