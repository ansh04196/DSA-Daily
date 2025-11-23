class Solution {
public:
    int helper(vector<vector<int>> &dp, vector<int> &nums, int n, int i, int rem){
        if (i >= n) return !rem ? 0 : -1e9;
        if (dp[i][rem] != -1) return dp[i][rem];
        int take = nums[i] + helper(dp, nums, n, i + 1, ((rem + (nums[i] % 3)) % 3));
        int dont = helper(dp, nums, n, i + 1, rem);
        return dp[i][rem] = max(take, dont);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (3, -1));
        return helper(dp, nums, n, 0, 0);
    }
};
