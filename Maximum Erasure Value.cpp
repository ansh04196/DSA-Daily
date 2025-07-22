class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0, curr = 0, res = 0;
        unordered_map<int, int> map;
        while(i < n && j < n){
            while(j < n && !map[nums[j]]) map[nums[j]]++, curr += nums[j++]; 
            res = max(res, curr);
            curr -= nums[i];
            map[nums[i++]]--;
        }
        return res;
    }
};
