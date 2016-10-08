char* convert(char* s, int numRows) {
	int i, j, n, sign;
	int len = strlen(s);
	char* out = (char*) malloc((len + 1) * sizeof(char));
	if (numRows < 2 || len <= numRows) return s;
	for (i = n = 0; i < numRows; i++) {
		if (i == 0 || i == numRows - 1) {
			for (j = i; j < len; j += 2 * numRows - 2) out[n++] = s[j];
		} else {
			sign = 0;
			for (j = i; j < len; ) {
				out[n++] = s[j];
				j += sign ? 2 * i : 2 * (numRows - 1 - i);
				sign = !sign;
			}
		}
	}
	out[n] = 0;
	return out;
}