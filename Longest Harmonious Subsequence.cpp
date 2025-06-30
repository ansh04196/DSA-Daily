class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> map;
        for (int i : nums) map[i]++;
        for (int i : nums){
            if (map[i + 1]) res = max(res, map[i] + map[i + 1]);
        }
        return res;
    }
};
