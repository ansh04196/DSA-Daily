class Solution {
public:
    bool isPossible(vector<vector<char>>& board, int r, int c, int value) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == value + '0') return false;
            if (board[i][c] == value + '0') return false;
            int row = (r / 3) * 3 + i / 3;
            int col = (c / 3) * 3 + i % 3;
            if (board[row][col] == value + '0') return false;
        }
        return true;
    }
    
    bool helper(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    for (int num = 1; num <= 9; num++) {
                        if (isPossible(board, r, c, num)) {
                            board[r][c] = num + '0';
                            if (helper(board)) return true;
                            else board[r][c] = '.'; // Undo the assignment and try the next number
                        }
                    }
                    return false; // No valid number found
                }
            }
        }
        return true; // All cells are filled
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};
