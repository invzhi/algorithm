#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int N;
	string color;
	map<string, int> balloon;
	while (cin >> N && N) {
		string maxColor;
		int maxNum = 0;
		while (N--) {
			cin >> color;
			balloon[color]++;
			if (balloon[color] > maxNum) {
				maxNum = balloon[color];
				maxColor = color;
			}
		}
		cout << maxColor << endl;
	}
	return 0;
}