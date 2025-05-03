class Solution {
public:
    int helper(vector<int> &tops, vector<int> &bottoms, int n, int side, int value){
        int res = 0;
        for (int i = 0; i < n; i++){
            if (tops[i] != value && bottoms[i] != value) return 1e9;
            if (!side && tops[i] != value) res++; 
            if (side && bottoms[i] != value) res++;
        }
        return res;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res1 = helper(tops, bottoms, tops.size(), 0, tops[0]);
        int res2 = helper(tops, bottoms, tops.size(), 0, bottoms[0]);
        int res3 = helper(tops, bottoms, tops.size(), 1, tops[0]);
        int res4 = helper(tops, bottoms, tops.size(), 1, bottoms[0]);
        int res = min({res1, res2, res3, res4});
        return res == 1e9 ? -1 : res;
    }
};
