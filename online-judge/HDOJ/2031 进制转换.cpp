#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, R;
	int tmp;
	while (cin >> N >> R) {
		bool isIntMin = false;
		int i = 0;
		char s[50];
		if (N == INT_MIN) {
			isIntMin = true;
			N++;
		}
		if (N < 0) {
			N = -N;
			cout << '-';
		}
		if (!N) cout << 0;
		while (N) {
			tmp = N % R;
			N /= R;
			if (tmp > 9) {
				tmp -= 10;
				s[i++] = 'A' + tmp;
			} else {
				s[i++] = '0' + tmp;
			}
		}
		if (isIntMin) {
			if (s[0] == '9') s[0] = 'A';
			else s[0]++;
		}
		while (i--) cout << s[i];
		cout << endl;
	}
	return 0;
}
