class Solution {
public:
	string getNext(string& s) {
		string next = "";
		int cnt = 1;
		int end = s.length() - 1;
		for (int i = 0; i < end; i++) {
			if (s[i] == s[i + 1]) cnt++;
			else {
				next += '0' + cnt;
				next += s[i];
				cnt = 1;
			}
		}
		next += '0' + cnt;
		next += s[end];
		return next;
	}

	string countAndSay(int n) {
		string s = "1";
		for (int i = 1; i < n; i++) s = getNext(s);
		return s;
	}
};
