/*Brute Force Algorithm*/
int strStr(char* haystack, char* needle) {
	int i, j, start;
	if (needle[0] == 0) return 0;
	start = strlen(haystack) - strlen(needle);
	for (i = 0; i <= start; i++) {
		for (j = 0; haystack[i + j] == needle[j]; j++) {
			if (needle[j + 1] == 0) return i;
		}
	}
	return -1;
}
/*END*/

/*KMP Algorithm*/
int* getNext(char* a, int length) {
	int i = 2, j = 0;
	int* next = (int*) malloc(sizeof(int) * length);
	next[0] = -1;
	next[1] = 0;
	while (i < length) {
		if (a[i - 1] == a[j]){
			if (a[i] == a[++j]) next[i++] = next[j];
			else next[i++] = j;
		} else if (j > 0) j = next[j];
		else next[i++] = 0;
	}
	return next;
}

int strStr(char* haystack, char* needle) {
	if (needle[0] == 0) return 0;
	int i, j;
	int m = strlen(haystack);
	int n = strlen(needle);
	int* next = getNext(needle, n);
	i = j = 0;
	while (i < m && j < n) {
		if (j == -1 || haystack[i] == needle[j]) {
			i++;
			j++;
		} else j = next[j];
	}
	free(next);
	return j == n ? i - j : -1;
}
/*END*/
