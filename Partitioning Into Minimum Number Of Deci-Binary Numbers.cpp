class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        for (char ch : n) res = max(res, ch - '0');
        return res;
    }
};
