class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> s;
        int res = 0;
        for (int i : nums) {
            while (!s.empty() && s.back() > i) s.pop_back();
            if (!i) continue;
            if (s.empty() || s.back() < i) s.push_back(i), res++;
        }
        return res;
    }
};
