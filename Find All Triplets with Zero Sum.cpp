// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Set to handle duplicates
        set<vector<int>> resSet;
        int n = arr.size();
        unordered_map<int, vector<pair<int, int>>> mp;

        // Store sum of all the pairs with their indices
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                mp[arr[i] + arr[j]].push_back({i, j});
        }

        for (int i = 0; i < n; i++) {

            // Find remaining value to get zero sum
            int rem = -arr[i];
            if (mp.find(rem) != mp.end()) {
                vector<pair<int, int>> pairs = mp[rem];
                for (auto p : pairs) {

                    // Ensure no two indices are same in triplet
                    if (p.first != i && p.second != i) {
                        vector<int> curr = {i, p.first, p.second};
                        sort(curr.begin(), curr.end());
                        resSet.insert(curr);
                    }
                }
            }
        }

        vector<vector<int>> res(resSet.begin(), resSet.end());
        return res;
    }
};
