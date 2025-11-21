class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size(), count = 0;
        vector<int> first(26, 1e9), last(26, -1);
        for (int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            first[idx] = min(first[idx], i);
            last[idx] = max(last[idx], i);
        }
        for (int i = 0; i < 26; i++){
            if (first[i] == 1e9) continue;
            unordered_set<char> uniqueCharBetween;
            for (int j = first[i] + 1; j < last[i]; j++) uniqueCharBetween.insert(s[j]); 
            count += uniqueCharBetween.size();
        }
        return count;
    }
};
