#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a[100];
	int n;
	while (cin >> n && n) {
		int first = true;
		int min, minI;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (first) {
				first = false;
				min = a[0];
				minI = 0;
			} else if (a[i] < min) {
				min = a[i];
				minI = i;
			}
		}
		a[minI] = a[0];
		cout << min;
		for (int i = 1; i < n; i++) cout << ' ' << a[i];
		cout << endl;
	}
	return 0;
}