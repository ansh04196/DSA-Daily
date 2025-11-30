class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long n = nums.size(), res = 1e18, curr = 0;
        long long total = accumulate(nums.begin(), nums.end(), 0LL), rem = total % p;
        unordered_map<long long, long long> map;
        map[0] = -1;
        if (!rem) return 0;
        for (long long i = 0; i < n; i++){
            curr += nums[i];
            long long currMod = curr % p, req = (currMod - rem + p) % p;
            if (map.find(req) != map.end()) res = min(res, i - map[req]);
            map[currMod] = i;
        }
        return res == n ? -1 : res;
    }
};
