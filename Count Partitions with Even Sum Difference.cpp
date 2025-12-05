class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size(), sum = 0, res = 0, total = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n - 1; i++){
            sum += nums[i];
            res += !(abs(total - (2 * sum)) % 2);
        }
        return res;
    }
};
