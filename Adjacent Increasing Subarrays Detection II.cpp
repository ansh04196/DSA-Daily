class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), len = 1, prev = 0;
        for (int i = 1; i < n && max(len / 2, min(len, prev)) < k; i++){
            if (nums[i] > nums[i - 1]) len++;
            else prev = len, len = 1;
        }
        return max(len / 2, min(len, prev)) >= k;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int lo = 1, hi = nums.size(), k = 1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if (hasIncreasingSubarrays(nums, mid)) k = mid, lo = mid + 1;
            else hi = mid - 1; 
        }   
        return k;
    }
};
