class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, int> map;
        for (int i : nums) map[i]++;
        while(map[original]) original *= 2;
        return original;
    }
};
