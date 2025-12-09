class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size(), res = 0;
        const int MOD = 1e9 + 7;
        unordered_map<int, int> freq, prevFreq;
        for (int i : nums) freq[i]++;
        for (int j = 0; j < n; j++){
            int a = nums[j] * 2;
            int left = prevFreq[a];
            prevFreq[nums[j]]++;
            int right = freq[a] - prevFreq[a];
            res = (res + (left * 1LL * right % MOD)) % MOD;
        }
        return res;
    }
};
