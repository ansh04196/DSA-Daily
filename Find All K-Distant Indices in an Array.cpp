class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size(), r = 0;
        vector<int> res;
        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                int l = max(r, j - k);
                r = min(n - 1, j + k) + 1;
                for (int i = l; i < r; i++) res.push_back(i);
            }
        }
        return res;
    }
};
