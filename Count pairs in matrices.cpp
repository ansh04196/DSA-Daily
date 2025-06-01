class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        unordered_map<int,int> mpp;
        for(int i=0;i<mat1.size();i++){
            for(int j=0;j<mat1[0].size();j++){
                mpp[mat1[i][j]]++;
            }
        }
        
        int cnt = 0;
        for(int i=0;i<mat2.size();i++){
            for(int j=0;j<mat2[0].size();j++){
                int rem = x - mat2[i][j];
                if(mpp.find(rem) != mpp.end()){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
//GFG POTD solution for 01 June
