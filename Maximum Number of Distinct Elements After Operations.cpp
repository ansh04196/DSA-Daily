class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, prev = -1e9;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int l = max(nums[i] - k, prev + 1);
            if (l <= nums[i] + k) prev = l, res++;
        }
        return res;
    }
};
