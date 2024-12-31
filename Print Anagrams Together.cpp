//Back-end complete function Template for C++

class Solution {
  public:
    vector<vector<string> > anagrams(vector<string>& arr) {
        vector<vector<string> > result;

        // hash map to maintain groups of anagrams
        unordered_map<string, vector<string> > umap;

        for (int i = 0; i < arr.size(); i++) {
            string s = arr[i];

            // sort each string
            sort(s.begin(), s.end());

            // add original string to corresponding sorted string in hash map
            umap[s].push_back(arr[i]);
        }
        for (auto itr = umap.begin(); itr != umap.end(); itr++)
            result.push_back(itr->second);

        return result;
    }
};
