class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> res;
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < nums.size() - 2; i += 3){
            if (arr[i + 2] - arr[i] > k) return {};
            res.push_back({arr[i], arr[i + 1], arr[i + 2]});
        }
        return res;
    }
};
