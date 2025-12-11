class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int res = 0;
        unordered_map<int, set<int>> x, y;
        for (auto it : buildings) y[it[0]].insert(it[1]), x[it[1]].insert(it[0]);
        for (auto it : buildings){
            bool flag1 = it[0] > *(x[it[1]].begin()) && it[0] < *(--x[it[1]].end());
            bool flag2 = it[1] > *(y[it[0]].begin()) && it[1] < *(--y[it[0]].end()); 
            res += flag1 && flag2;
        }
        return res;
    }
};
