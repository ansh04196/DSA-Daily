class Solution {
public:
    int helper(vector<vector<int>> &dp, string &s, int n, int seats, int i){
        if (i == n) return seats == 2 ? 1 : 0;
        if (dp[i][seats] != -1) return dp[i][seats];
        int take = 0, dont = 0, mod = 1e9 + 7;
        if (s[i] == 'P'){
            take = helper(dp, s, n, seats, i + 1);
            if (seats == 2) dont = helper(dp, s, n, 0, i + 1);
        }
        else{
            if (seats < 2) take = helper(dp, s, n, seats + 1, i + 1);
            else dont = helper(dp, s, n, 1, i + 1);
        }
        return dp[i][seats] = (take + dont) % mod;
    }
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return helper(dp, corridor, n, 0, 0);
    }
};
