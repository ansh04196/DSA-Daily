
class Solution {
public:
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>>& mat) {
        solve(mat);
    }

private:
    bool solve(vector<vector<int>>& mat) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (mat[row][col] == 0) {  // Find an empty cell
                    for (int num = 1; num <= 9; num++) {  // Try numbers 1-9
                        if (isValid(mat, row, col, num)) {
                            mat[row][col] = num;  // Place the number

                            if (solve(mat)) {  // Recursively solve the rest
                                return true;
                            }

                            mat[row][col] = 0;  // Backtrack
                        }
                    }
                    return false;  // No valid number found
                }
            }
        }
        return true;  // Sudoku solved
    }

    bool isValid(vector<vector<int>>& mat, int row, int col, int num) {
        // Check if 'num' is not in the current row, column, and 3x3 sub-box
        for (int i = 0; i < 9; i++) {
            if (mat[row][i] == num || mat[i][col] == num || 
                mat[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) {
                return false;
            }
        }
        return true;
    }
};


//GFG POTD solution for 31 January
