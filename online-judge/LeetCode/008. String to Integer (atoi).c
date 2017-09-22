int myAtoi(char* str) {
	int result = 0;
	bool isNegative = false;
	while(*str == ' ') str++;
	if(*str == '+') str++;
	else if(*str == '-') {
		isNegative = true;
		str++;
	}
	while(*str) {
		if (*str - '0' == 0 && result == 0) {
			str++;
			continue;
		}
		if (*str - '0' < 0 || *str - '9' > 0) return isNegative ? -result : result;
		if (result > INT_MAX / 10) return isNegative ? INT_MIN : INT_MAX;
		result *= 10;
		if ((*str - '0') > (INT_MAX - result)) return isNegative ? INT_MIN : INT_MAX;
		result += *str - '0';
		str++;
	}
	return isNegative ? -result : result;
}
