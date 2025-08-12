class Solution {
public:
    const int mod = 1e9 + 7;
    long long helper(vector<vector<long long>> &dp, int n, int x, long long num, long long i){
        if (num == n) return 1;
        if (num > n || i == n + 1) return 0; 
        if (dp[i][num] != -1) return dp[i][num];
        long long pick = helper(dp, n, x, num + pow(i, x), i + 1) % mod;
        long long dont = helper(dp, n, x, num, i + 1) % mod;
        return dp[i][num] = (pick + dont) % mod;
    }
    int numberOfWays(int n, int x) {
        vector<vector<long long>> dp(n + 1, vector<long long> (n + 1, -1));
        return helper(dp, n, x, 0, 1) % mod;
    }
};
