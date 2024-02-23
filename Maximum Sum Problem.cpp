class Solution {
public:
    int solve(int n, vector<int>& dp)
    {
        // base conditions
        if (n == 0 || n == 1) {
            return n;
        }

        // if dp[n] already calculated then directly return
        // so no overlapping problem calls
        if (dp[n] != -1) {
            return dp[n];
        }

        // break the number and return what maximum you can
        // get
        return dp[n]
               = max((solve(n / 2, dp) + solve(n / 3, dp)
                      + solve(n / 4, dp)),
                     n);
    }

    int maxSum(int n)
    {
        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};
