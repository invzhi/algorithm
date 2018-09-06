int lengthOfLongestSubstring(char* s) {
	int i = 0;
	int left = 0, num = 0;
	int len = strlen(s);
	int index[128];
	memset(index, 0, sizeof(index));
	for (i = 0; i < len; i++) {
		if (index[s[i]] > left) left = index[s[i]];
		if (i - left + 1 > num) num = i - left + 1;
		index[s[i]] = i + 1;
	}
	return num;
}
