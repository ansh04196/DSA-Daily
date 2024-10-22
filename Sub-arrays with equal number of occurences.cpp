class Solution {
   public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0, diff = 0;
        for (int ele : arr) {
            diff += ele == x ? 1 : ele == y ? -1 : 0;
            ans += mp[diff]++;
        }
        return ans;
    }
};
