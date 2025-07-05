class Solution {
public:
    int findLucky(vector<int>& arr) {
        int res = -1;
        unordered_map<int, int> map;
        for (int i : arr) map[i]++;
        for (auto it : map){
            if (it.second == it.first) res = max(res, it.first);
        }
        return res;
    }
};
