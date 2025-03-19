class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), res = 0, flag = 1;
        for (int i = 0; i <= n - 3; i++){
            if (!nums[i]){
                for (int j = 0; j < 3; j++) nums[j + i] = nums[j + i] == 1 ? 0 : 1;
                res++;
            }
        }
        for (int i = 0; i < n; i++) flag &= nums[i] == 1;
        return flag ? res : -1;
    }
};
