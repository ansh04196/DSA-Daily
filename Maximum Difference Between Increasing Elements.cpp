class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi = nums.back(), res = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            res = max(res, maxi - nums[i]);
            maxi = max(maxi, nums[i]);
        }
        return !res ? -1 : res;
    }
};
