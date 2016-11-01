#include <cstdio>
#include <algorithm>

using namespace std;

int type, val;
int ansAns;
int ansType, ansNum, ansMax;
int kind[26];
int ans[4], cur[4];

void DFS(int lastC, int c, int curType, int curNum, int curMax, int curVal) {
	if (curNum > 4 || curNum == 4 && curVal != val) return;
	if (val == curVal) {
		if (curType > ansType ||
			curType == ansType && curNum < ansNum ||
			curType == ansType && curNum == ansNum && curMax > ansMax
		   ) {
			ansAns = 1;
			ansType = curType;
			ansNum = curNum;
			ansMax = curMax;
			for (int i = 0; i < ansNum; i++) ans[i] = cur[i];
		} else if (curType == ansType && curNum == ansNum && curMax == ansMax) {
			ansAns++;
		}
		return;
	}
	for (int i = c; i < type; i++) {
		if (curVal + kind[i] > val) return;
		cur[curNum] = kind[i];
		DFS(i, i, curType + (i != lastC), curNum + 1, max(curMax, kind[i]), curVal + kind[i]);
	}
}

int main() {
	while (scanf("%d", &kind[0]) != EOF) {
		type = 0;
		while (kind[type]) scanf("%d", &kind[++type]);
		sort(kind, kind + type);
		while (scanf("%d", &val) && val) {
			ansAns = ansType = ansNum = ansMax = 0;
			DFS(-1, 0, 0, 0, 0, 0);
			if (ansAns == 0) printf("%d ---- none\n", val);
			else if (ansAns > 1) printf("%d (%d): tie\n", val, ansType);
			else {
				printf("%d (%d):", val, ansType);
				for (int i = 0; i < ansNum; i++) printf(" %d", ans[i]);
				printf("\n");
			}
		}
	}
	return 0;
}
