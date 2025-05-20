class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (auto it : queries) diff[it[0]] += 1, diff[it[1] + 1] -= 1;
        for (int i = 1; i < n; i++) diff[i] += diff[i - 1];
        for (int i = 0; i < n; i++){
            if (nums[i] > diff[i]) return false;
        }
        return true;
    }
};
