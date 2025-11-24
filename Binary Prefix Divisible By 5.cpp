class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        vector<bool> res(n, false);
        for (int i = 0; i < n; i++){
            sum = ((2 * sum) + nums[i]) % 5;
            res[i] = !sum;
        }
        return res;
    }
};
