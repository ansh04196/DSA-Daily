class Solution {
public:
    int possibleIndex(vector<int> &potions, int m, int spell, long long success){
        int lo = 0, hi = m - 1, res = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            long long product = (long long)potions[mid] * (long long)spell;
            if (product >= success) res = mid, hi = mid - 1;
            else lo = mid + 1;
        }
        return res;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++){
            int index = possibleIndex(potions, m, spells[i], success);
            if (index != -1) res[i] = m - index;
        }
        return res;
    }
};
