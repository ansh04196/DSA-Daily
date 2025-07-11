class Solution {
  public:
    int countConsec(int n) {
   
    vector<int> dp(n + 1), dp0(n + 1), dp1(n + 1);
    dp0[1] = 1;
    dp1[1] = 1;
    dp[1] = 2;
    for (int i = 2; i <= n; i++) {
        dp0[i] = dp0[i - 1] + dp1[i - 1];
        dp1[i] = dp0[i - 1];
        dp[i] = dp0[i] + dp1[i];
    }
    return (1 << n) - dp[n];
    }
};
//GFG POTD solution for 11 July
