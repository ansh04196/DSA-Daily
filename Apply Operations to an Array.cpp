class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> res = nums, ans;
        for (int i = 0; i < n - 1; i++){
            if (res[i] == res[i + 1]) res[i] *= 2, res[i + 1] = 0;
        }
        for (int i = 0; i < n; i++){
            if (res[i]) ans.push_back(res[i]);
        }
        while(ans.size() < n) ans.push_back(0);
        return ans;
    }
};
