#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 6

int reverse(char s[], int sr[]) {
	int dot = 0;
	int temp[LENGTH - 1];
	memset(temp, 0, sizeof(temp));
	for (int i = 0, j = 0; i < LENGTH; i++)	{
		if (s[i] != '.') temp[j++] = s[i] - '0';
		else dot = i;
	} 
	for (int i = 0; i < LENGTH - 1; i++) sr[i] = temp[LENGTH - 2 - i];
	return LENGTH - 1 - dot;
}

void mult(int ans[], int s[])
{
	int temp[130];
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < LENGTH - 1; i++) {
		for (int j = 0; j < 130; j++) {
			if (ans[j])	temp[i + j] += s[i] * ans[j];
		}
	}
	int last = 0;
	for (int i = 0; i < 130; i++) {
		ans[i] = (last + temp[i]) % 10;
		last = (last + temp[i]) / 10;
	}
}

int main() {
	int n;
	char s[LENGTH];
	int sr[LENGTH - 1], ans[130];
	while (scanf("%s%d", s, &n) != EOF) {
		memset(sr, 0, sizeof(sr));
		memset(ans, 0, sizeof(ans));
		int dot = n * reverse(s, sr);
		ans[0] = 1;
		for (int i = 0; i < n; i++) mult(ans, sr);
		int begin = 129;
		int end = 0;
		while (begin && !ans[begin]) begin--;
		while (end < 130 && !ans[end]) end++;
		for (int i = begin; i >= dot; i--) printf("%d",ans[i]);
		if (dot && dot > end) printf(".");
		for (int i = dot - 1; i >= end; i--) printf("%d", ans[i]);
		printf("\n");
	}
	return 0;
}