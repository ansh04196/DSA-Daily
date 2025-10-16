class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size(), res = 0;
        vector<int> freq(value, 0);
        for (int i : nums) freq[(i % value + value) % value]++;
        while (freq[res % value]) freq[res % value]--, res++;
        return res;
    }
};
