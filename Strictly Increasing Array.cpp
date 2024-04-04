class Solution {
  public:

    int min_operations(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            int temp = 0;
            for (int j = 0; j < i; j++) {
                // If nums[i] is greater than nums[j] then it can be added to the set of
                // LIS
                if (nums[i] > nums[j])
                    if (nums[i] - nums[j] > i - j - 1)
                        temp = max(temp, dp[j]);
            }
            // length of maximum increasing subsequnce whose last element is nums[i]
            dp[i] = max(dp[i], 1 + temp);
        }
        // total opeartion needs to  apply
        return n - *max_element(dp.begin(), dp.end());
    }
};
