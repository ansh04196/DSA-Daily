class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(), res = 0;
        set<int> sets;
        for (int i : nums) sets.insert(i);
        for (int i = 0; i < n; i++){
            int j = i;
            set<int> temp;
            while(j < n && temp.size() != sets.size()) temp.insert(nums[j++]);
            if (sets.size() == temp.size()) res += (n - j + 1);
        }
        return res;
    }
};
