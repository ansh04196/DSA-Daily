class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for (int x : nums){
            int pos = 1, num = -1;
            while((x & pos) != 0) num = x - pos, pos <<= 1;
            res.push_back(num);
        }   
        return res;
    }
};
