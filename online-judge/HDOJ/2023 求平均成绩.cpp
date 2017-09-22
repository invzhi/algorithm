#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int score[50][5];
int stu[50];
int cou[5];

int main() {
	int n, m;
	while (cin >> n >> m) {
		memset(stu, 0, n*sizeof(int));
		memset(cou, 0, m*sizeof(int));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> score[i][j];
				stu[i] += score[i][j];
				cou[j] += score[i][j];
			}
		}
		printf("%.2f", (double)stu[0]/m);
		for (int i = 1; i < n; i++) printf(" %.2f", (double)stu[i]/m);
		cout << endl;
		printf("%.2f", (double)cou[0]/n);
		for (int i = 1; i < m; i++) printf(" %.2f", (double)cou[i]/n);
		cout << endl;
		int goodStu = 0;
		for (int i = 0; i < n; i++) {
			bool isGood = true;
			for (int j = 0; j < m; j++) {
				if (score[i][j] * n < cou[j]) {
					isGood = false;
					break;
				}
			}
			if (isGood) goodStu++;
		}
		cout << goodStu << endl << endl;
	}
	return 0;
}
