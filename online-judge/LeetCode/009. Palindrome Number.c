bool isPalindrome(int x) {
	if (x < 0 || x % 10 == 0 && x > 0) return false;
	else if (x < 10) return true;
	else {
		int num = 0;
		int y = x;
		while (x) {
			num = 10 * num + x % 10;
			x /= 10;
		}
		return num == y;
	}
}
