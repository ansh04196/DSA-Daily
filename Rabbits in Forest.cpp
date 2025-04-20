class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        vector<int> freq(1000, 0);
        for(int i : answers) res += (freq[i]++ % (i + 1) == 0) * (i + 1);
        return res;
    }
};
