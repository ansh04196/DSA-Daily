class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
         int n=mat.size();
         int maxi=0;
         vector<int>row(n,0),col(n,0);
         for(auto i=0;i<n;i++){
             for(auto j=0;j<n;j++){
                 row[i]+=mat[i][j];
                 col[j]+=mat[i][j];
                 maxi=max(maxi,max(row[i],col[j]));
             }
         }
         int diff=0;
         for(auto i=0;i<n;i++){
             diff+=(maxi-row[i]);
         }
         return diff;
    }
};
//GFG POTD solution for 28 July
