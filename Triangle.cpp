class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = size(triangle), ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for (int i = 0; i < n; i++) dp[n - 1][i] = triangle[n - 1][i];
        for (int i = n - 2; i >= 0; i--){
            for (int j = 0; j <= i; j++){
                if (j + 1 > i) dp[i][j] += triangle[i][j] + dp[i + 1][j];
                dp[i][j] = min(triangle[i][j] + dp[i + 1][j],triangle[i][j] + dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
};
