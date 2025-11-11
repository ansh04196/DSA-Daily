class Solution {
public:
    int countOnes(string &s){
        int ones = 0;
        for (char ch : s){
            if (ch == '1') ones++;
        }
        return ones;
    }    
    int countZeroes(string &s){
        int zeroes = 0;
        for (char ch : s){
            if (ch == '0') zeroes++;
        }
        return zeroes;
    }
    int helper(vector<string>& arr, vector<vector<vector<int>>>& dp, int m, int n, int i){
        if (m < 0 || n < 0) return -1;
        if (i == 0) return 0;
        if (dp[i][m][n] != -1) return dp[i][m][n];   
        int zeroes = countZeroes(arr[i - 1]), ones = countOnes(arr[i - 1]);
        int take = 1 + helper(arr, dp, m - zeroes, n - ones, i - 1);
        int not_take = helper(arr, dp, m, n, i - 1);
        return dp[i][m][n] = max(take, not_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return helper(strs, dp, m, n, k);
    }
};
