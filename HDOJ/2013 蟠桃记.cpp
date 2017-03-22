#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int p = 1;
		n--;
		while (n--) {
			p++;
			p *= 2;
		}
		cout << p << endl;
	}
	return 0;
}