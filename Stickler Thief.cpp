class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>dp(n,0);
        dp[0] = arr[0];
        dp[1] = max(arr[1],arr[0]);
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1],arr[i] + dp[i-2]);
        }
        return dp[n-1];
    }
};
