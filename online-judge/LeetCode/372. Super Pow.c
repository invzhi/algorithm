int quickPow(int a, int b) {
	int ans = 1;
	a %= 1337;
	while (b) {
		if (b & 1) ans = ans * a % 1337;
		a = a * a % 1337;
		b >>= 1;
	}
	return ans;
}

int superPow(int a, int* b, int bSize) {
	int i, ans = 1;
	for (i = bSize - 1; i >= 0; i--) {
		ans = ans * quickPow(a, b[i]) % 1337;
		a = quickPow(a, 10);
	}
	return ans;
}
