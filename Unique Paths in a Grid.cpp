class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                grid[i][j]=grid[i][j]^1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==0)
            {
                while(i<n)
                {
                    grid[i][0]=0;
                    i++;
                }
                break;
            }
        }
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==0)
            {
                while(j<m)
                {
                    grid[0][j]=0;
                    j++;
                }
                break;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(grid[i][j]==1)
                  grid[i][j]=grid[i-1][j]+grid[i][j-1];
            }
        }
        return grid[n-1][m-1];
        
    }
};
//GFG POTD solution for 02 June
