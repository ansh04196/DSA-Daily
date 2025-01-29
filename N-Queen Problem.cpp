// User function Template for C++

class Solution {
  public:
    vector<vector<int>> nQueen(int n) {
        vector<bool> col(n, false);
        vector<bool> ndiag(2 * n - 1, false);
        vector<bool> rdiag(2 * n - 1, false);
        vector<vector<int>> res;
        vector<int> tmp;
        solve(n, 0, col, ndiag, rdiag, res, tmp);
        return res;
    }

private:
    void solve(int n, int currR, vector<bool>& col, vector<bool>& ndiag, vector<bool>& rdiag,
               vector<vector<int>>& res, vector<int>& tmp) {
        if (currR == n) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !ndiag[currR + i] && !rdiag[currR - i + n - 1]) {
                tmp.push_back(i + 1);
                col[i] = true;
                ndiag[currR + i] = true;
                rdiag[currR - i + n - 1] = true;
                
                solve(n, currR + 1, col, ndiag, rdiag, res, tmp);
                
                tmp.pop_back();
                col[i] = false;
                ndiag[currR + i] = false;
                rdiag[currR - i + n - 1] = false;
            }
        }
    }
};

//GFG POTD solution for 30 January
