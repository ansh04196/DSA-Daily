class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), maxi = 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), prev(n, -1), res;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxi]) maxi = i;
        }
        while (maxi != -1) {
            res.push_back(nums[maxi]);
            maxi = prev[maxi];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
