class Solution {
public:
    void performSortOps(vector<vector<int>> &grid, int r, int c, bool asc){
        int n = grid.size();
        vector<int> temp;
        for (int i = r, j = c; i < n && j < n; i++, j++) temp.push_back(grid[i][j]);
        if (!asc) sort(temp.begin(), temp.end());
        else sort(temp.rbegin(), temp.rend());
        for (int i = r, j = c; i < n && j < n; i++, j++) {
            grid[i][j] = temp.back();
            temp.pop_back();
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int j = 1; j < n; j++) performSortOps(grid, 0, j, true);
        for (int i = 0; i < n; i++) performSortOps(grid, i, 0, false);
        return grid;
    }
};
