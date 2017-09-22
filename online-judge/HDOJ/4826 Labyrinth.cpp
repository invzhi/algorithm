#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define N 101

#define MAX(A, B) ((A) > (B) ? (A) : (B))

using namespace std;

int map[N][N];
int dp1[N], dp2[N];

int main() {
	int T;
	cin >> T;
	for (int k = 1; k <= T; ++k) {
		int m, n;
		cin >> m >> n;
		for (int j = 1; j <= m; j++) {
			for (int i = 1; i <= n; i++) {
				cin >> map[j][i];
			}
		}
		for (int j = 2; j <= m; j++) map[j][1] += map[j - 1][1];
		for (int j = 2; j <= n; j++) {
			dp1[1] = map[1][j - 1] + map[1][j];
			dp2[m] = map[m][j - 1] + map[m][j];
			for (int i = 2; i <= m; i++) dp1[i] = MAX(map[i][j - 1], dp1[i - 1]) + map[i][j];
			for (int i = m - 1; i >= 1; i--) dp2[i] = MAX(map[i][j - 1], dp2[i + 1]) + map[i][j];
			for (int i = 1; i <= m; i++) map[i][j] = MAX(dp1[i], dp2[i]);
		}
		cout << "Case #" << k << ":" << endl;
		cout << map[1][n] << endl;
	}
	return 0;
}
