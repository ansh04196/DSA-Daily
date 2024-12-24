class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n = mat.size(), m = mat[0].size();

        int C0 = 1;

        // Traverse the mat and
        // mark 1st row & 1st
        // col as follows:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {

                    // mark i-th row:
                    mat[i][0] = 0;

                    // mark j-th column:
                    if (j == 0)
                        C0 = 0;
                    else
                        mat[0][j] = 0;
                }
            }
        }

        // Mark with 0 from (1,1)
        // to (n-1, m-1):
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][j] != 0) {

                    // Check for col & row:
                    if (mat[i][0] == 0 || mat[0][j] == 0) {
                        mat[i][j] = 0;
                    }
                }
            }
        }

        // Finally mark the
        // 1st row then 1st col:
        if (mat[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                mat[0][j] = 0;
            }
        }
        if (C0 == 0) {
            for (int i = 0; i < n; i++) {
                mat[i][0] = 0;
            }
        }
    }
};
