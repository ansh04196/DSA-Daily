class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), i = 1, p = 0, q = 0;
        while(i < n && nums[i] > nums[i - 1]) i++;
        p = i - 1;
        while(i < n && nums[i] < nums[i - 1]) i++;
        q = i - 1;
        while(i < n && nums[i] > nums[i - 1]) i++;
        return p != q && p != 0 && (i - 1 == n - 1) && (i - 1 != q);
    }
};
