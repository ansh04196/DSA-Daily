class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        vector<int> res = digits;
        while(i >= 0){
            if (res[i] != 9) {
                res[i]++;
                break;
            }
            else res[i--] = 0;
        }
        if (i == -1) res.insert(res.begin(), 1);
        return res;
    }
};
