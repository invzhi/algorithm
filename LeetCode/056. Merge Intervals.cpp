/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool cmp(Interval a, Interval b) {
	return a.start < b.start;
}

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.size() < 2) return intervals;
		sort(intervals.begin(), intervals.end(), cmp);
		vector<Interval> ans;
		ans.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i].start <= ans.back().end) {
				ans.back().end = max(intervals[i].end, ans.back().end);
			} else ans.push_back(intervals[i]);
		}
		return ans;
	}
};