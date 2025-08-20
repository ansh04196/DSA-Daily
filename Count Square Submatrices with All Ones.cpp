class Solution {
public:
    int helper(vector<vector<int>>& matrix, vector<vector<int>> &dp, int i, int j){
        if (i < 0 || j < 0 || !matrix[i][j]) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int up = helper(matrix, dp, i - 1, j);
        int left = helper(matrix, dp, i, j - 1);
        int diag = helper(matrix, dp, i - 1, j - 1);
        return dp[i][j] = 1 + min({up, left, diag});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) res += helper(matrix, dp, i, j);
        }
        return res;
    }
};
