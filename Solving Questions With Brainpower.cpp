class Solution {
public:
    long long helper(vector<vector<int>> &arr, vector<long long> &dp, int n, int i){
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        long long solve = arr[i][0] + helper(arr, dp, n, i + arr[i][1] + 1);
        long long dont = helper(arr, dp, n, i + 1);
        return dp[i] = max(solve, dont);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, -1);
        return helper(questions, dp, n, 0);
    }
};
