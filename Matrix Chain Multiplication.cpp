
class Solution {
    public:
  int solve(vector<int> &arr, int i, int j) {
    if (i + 1 == j) return 0;
    
    int result = INT_MAX;
    
    for (int k = i + 1; k < j; k++) {
        int cost = solve(arr, i, k) +solve(arr, k, j) + arr[i] * arr[j] * arr[k];
        result = min(result, cost);
    }
    return result;
  }
    int solveMem(vector<int> &arr, int i, int j,vector<vector<int>>&dp){
    if (i + 1 == j) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int result = INT_MAX;
    
    for (int k = i + 1; k < j; k++) {
        int cost = solveMem(arr, i, k,dp) +solveMem(arr, k, j,dp) + arr[i] * arr[j] * arr[k];
        result = min(result, cost);
    }
    return dp[i][j]=result;
  }
    int solveTab(vector<int>&arr){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int length = 2;length<n;length++)
        {
            for(int i = 0;i<n- length;i++)
            {
                int j = i + length;
                dp[i][j] =INT_MAX;
                
                for(int k = i+1;k<j;k++)
                {
                    int cost = dp[i][k] + dp[k][j] + arr[i]*arr[j]*arr[k];
                    dp[i][j] = min(dp[i][j],cost);
                }
            }
        }
        int ans = dp[0][n-1];
        return ans;
    }
   
    int matrixMultiplication(vector<int> &arr) {
    //   return solve(arr,0,arr.size()-1);
       vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,-1));
    //   return solveMem(arr,0,arr.size()-1,dp);
    return solveTab(arr);
    }
};


//GFG POTD solution for 24 March
