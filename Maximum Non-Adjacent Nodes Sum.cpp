class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> freqMap(n, vector<int> (26, 0));
        vector<string> res;
        for (int i = 0; i < n; i++){
            for (char ch : words[i]) freqMap[i][ch - 'a']++;
        }
        for (int i = 0; i < n; i++){
            int j = i + 1;
            while(j < n && freqMap[i] == freqMap[j]) j++;
            res.push_back(words[i]);
            i = j - 1;
        }
        return res;
    }
};
