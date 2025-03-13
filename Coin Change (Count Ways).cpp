
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int t[1001][1001];
    int findknap(int W, vector<int> &val, vector<int> &wt,int n){
        
        if(n==0 || W==0) return 0;
        if( t[n][W]!=-1) return  t[n][W];
        if(wt[n-1]<=W) return t[n][W]= max(val[n-1]+findknap(W-wt[n-1],val,wt,n-1),findknap(W,val,wt,n-1));
        
        else return  t[n][W]=findknap(W,val,wt,n-1);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        memset(t,-1,sizeof(t));
        return findknap(W,val,wt,n);
    }
};


//GFG POTD solution for 13 March
