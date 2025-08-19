class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        for (int i = 0; i < nums.size(); i++){
            if (!nums[i]){
                int j = i;
                while(j < nums.size() && !nums[j]) j++;
                long long size = j - i;
                res += ((size * (size + 1)) / 2);
                i = j - 1;
            }
        }
        return res;
    }
};
