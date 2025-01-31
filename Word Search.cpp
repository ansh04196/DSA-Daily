class Solution {
  public:
    bool findMatch(vector<vector<char>> &mat, string word, int x, int y, int wIdx) {
        int wLen = word.length();
        int n = mat.size();
        int m = mat[0].size();
    
        if (wIdx == wLen)
            return true;
    
        if (x < 0 || y < 0 || x >= n || y >= m)
            return false;
    
        if (mat[x][y] != word[wIdx])
            return false;
    
        char temp = mat[x][y];
        mat[x][y] = '#';
    
        bool res = findMatch(mat, word, x - 1, y, wIdx + 1) ||
                   findMatch(mat, word, x + 1, y, wIdx + 1) ||
                   findMatch(mat, word, x, y - 1, wIdx + 1) ||
                   findMatch(mat, word, x, y + 1, wIdx + 1);
    
        mat[x][y] = temp;
        return res;
    }
    
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        int wLen = word.length();
        int n = mat.size();
        int m = mat[0].size();
    
        if (wLen > n * m)
            return false;
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) {
                    if (findMatch(mat, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};
