class Solution {
  public:
    vector<vector<int>>dp;
    int check(int m,int n,int x,int sum){
        if(n==0){
            return (sum==x)?1:0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        long long ways=0;
        for(int j=1;j<=m;j++){
            ways+=check(m,n-1,x,sum+j);
        }
        return dp[n][sum]=ways;
    }
    int noOfWays(int m, int n, int x) {
        // code here
        dp.resize(51,vector<int>(2501,-1));
        return check(m,n,x,0);
    }
};
//GFG POTD solution for 23 May
