class Solution {
  public:
    bool searchRowMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size();    // Number of rows
        int m = mat[0].size(); // Number of columns

        // Iterate over each row
        for (int i = 0; i < n; i++) {
            // Check if x could be in the current row
            if (x >= mat[i][0] && x <= mat[i][m - 1]) {
                // Perform binary search within this row
                int left = 0, right = m - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (mat[i][mid] == x) {
                        return true; // Found the target
                    } else if (mat[i][mid] < x) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }

        return false; // Element not found
    }
};
