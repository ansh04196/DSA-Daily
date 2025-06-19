class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, i = 0;
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        while(i < n){
            int start = arr[i];
            while(i < n && arr[i] - start <= k) i++;
            res++;
        }
        return res;
    }
};
