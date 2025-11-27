class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {       
        long long prefSum = 0, subMax = LLONG_MIN;
        vector<long long> minSoFar(k, LLONG_MAX / 2);
        minSoFar[(k - 1) % k] = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefSum += nums[i];
            subMax = max(subMax, prefSum - minSoFar[i % k]);
            minSoFar[i % k] = min(minSoFar[i % k], prefSum);
        }
        return subMax;
    }
};
