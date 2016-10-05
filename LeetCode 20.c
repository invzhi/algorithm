int isLeft(char c) {
	char left[] = {'(', '{', '['};
	int i, res = -1;
	for (i = 0; i < 3; i++) {
		if (c == left[i]) {
			res = i;
			break;
		}
	}
	return res;
}

bool isValid(char* s) {
	char right[] = {')', '}', ']'};
	char stack[10000];
	int i, n;
	int res = false;
	for (i = n = 0; s[i]; i++) {
		if (isLeft(s[i]) != -1) stack[n++] = s[i];
		else {
			if (n > 0 && right[isLeft(stack[n - 1])] == s[i]) n--;
			else break;
		}
	}
	return n == 0 && s[i] == 0;
}