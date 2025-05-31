class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        vector<int> temp;
        int n=mat.size();
        // code here
        for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            temp.push_back(mat[i][j]);
        }
    }
    sort(temp.begin(), temp.end());
    return temp[k-1]; 

    }
};
//GFG POTD solution for 31 May
