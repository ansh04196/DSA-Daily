
class Solution {
    
    int solve(int i,int n,vector<int>& dp){
        if(i>=n) return 1;
        if(dp[i]!=-1) return dp[i];
        int op1=solve(i+1,n,dp);
        int op2=solve(i+2,n,dp);
        return dp[i]=op1+op2;
    }
    
  public:
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1,-1);
        int res=solve(1,n,dp);
        return res; 
    }
};



 
