class Solution {
public:
	int minMoves2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int cnt = 0;
		for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
			cnt += nums[j] - nums[i];
		}
		return cnt;
	}
};