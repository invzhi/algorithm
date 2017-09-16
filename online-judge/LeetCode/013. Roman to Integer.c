int toNum(char c) {
	int value = 0;
	switch (c) {
		case 'I':
			value = 1;
			break;
		case 'V':
			value = 5;
			break;
		case 'X':
			value = 10;
			break;
		case 'L':
			value = 50;
			break;
		case 'C':
			value = 100;
			break;
		case 'D':
			value = 500;
			break;
		case 'M':
			value = 1000;
			break;
	}
	return value;
}

int romanToInt(char* s) {
    int i = 1;
    int now = 0;
    int pre = toNum(s[0]);
    int value = pre;
    while (s[i]) {
    	now = toNum(s[i]);
    	if (pre >= now) value += now;
    	else value += now - 2 * pre;
    	pre = now;
    	i++;
    }
    return value;
}