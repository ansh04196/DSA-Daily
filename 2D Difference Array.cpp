class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        int n = mat.size();
        int m = mat[0].size();
        int q = opr.size();
        
        vector<vector<int>> ans(n, vector<int> (m,0));
        
        for(int i=0;i<q;i++){
            int val = opr[i][0];
            int r1 = opr[i][1];
            int c1 = opr[i][2];
            int r2 = opr[i][3];
            int c2 = opr[i][4];
            ans[r1][c1] += val;
            if(c2<(m-1)) ans[r1][c2+1] -= val;
            if(r2<(n-1)) ans[r2+1][c1] -= val;
            if(r2<(n-1) && c2<(m-1)) ans[r2+1][c2+1] += val;
        }

        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                ans[i][j] += ans[i][j-1];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                ans[j][i] += ans[j-1][i];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[j][i] += mat[j][i];
            }
        }
        
        return ans;
        
    }
};
//GFG POTD solution for 03 August
