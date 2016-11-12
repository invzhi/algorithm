#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 6

int reverse(char s[], int sr[]) {
	int dot = 0;
	int temp[LENGTH - 1];
	memset(temp, 0, sizeof(temp));
	for (int i = 0, j = 0; i < LENGTH && s[i]; i++)	{
		if (s[i] != '.') temp[j++] = s[i] - '0';
		else dot = i;
	} 
	for (int i = 0; i < LENGTH - 1; i++) sr[i] = temp[LENGTH - 2 - i];
	return LENGTH - 1 - dot;
}

void mult(int s1[], int s2[])
{
	int temp[130];
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < LENGTH - 1; i++) {
		for (int j = 0; j < 130; j++) {
			temp[i + j] += s1[i] * s2[j];
		}
	}
	int last = 0;
	for (int i = 0; i < 130; i++) {
		s2[i] = (last + temp[i]) % 10;
		last = (last + temp[i]) / 10;
	}
}

int main() {
	int n;
	char s[LENGTH];
	int sr[LENGTH - 1], ans[130];
	while (scanf("%s%d", s, &n) != EOF) {
		memset (sr, 0, sizeof(sr));
		memset (ans, 0, sizeof(ans));
		int dot = reverse(s, sr);
		reverse(s, ans);
		for (int i = 1; i < n; i++) mult(sr, ans);
		int begin = 129;
		int end = 0;
		while (begin && !ans[begin]) begin--;
		while (end < 130 && !ans[end]) end++;
		for (int i = begin; i >= n * dot; i--) printf("%d",ans[i]);
		if (dot && n * dot > end) printf (".");
		for (int i = n * dot - 1; i >= end; i--) printf("%d", ans[i]);
		printf("\n");
	}
	return 0;
}