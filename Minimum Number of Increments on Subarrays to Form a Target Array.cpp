class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size(), res = target[0];
        for (int i = 1; i < n; ++i) res += max(target[i] - target[i - 1], 0);
        return res;
    }
};
