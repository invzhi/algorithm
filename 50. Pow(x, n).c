double myPow(double x, int n) {
	double ans = 1;
	unsigned int n_ = n < 0 ? -n : n;
	if (x == 1.0 || x == 0.0) return x;
	while (n_) {
		if ((n_ & 1u)) ans *= x;
		x *= x;
		n_ >>= 1;
	}
	return n < 0 ? 1 / ans : ans;
}