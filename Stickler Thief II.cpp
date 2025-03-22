
class Solution {
  public:
    int f(vector<int>& arr,int i,vector<int> &dp,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int nottake=f(arr,i+1,dp,n);
        int take=f(arr,i+2,dp,n)+arr[i];
        return  dp[i] = max(take,nottake);
    }
    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size();
        vector<int> dp;
        dp=vector<int> (n+1,-1);
        int a=f(arr,1,dp,n);
         dp=vector<int> (n+1,-1);
        int b=f(arr,2,dp,n-1)+arr[0];
        return max(a,b);
    }
};



//GFG POTD solution for 22 March
