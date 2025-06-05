class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char> equiv(26);
        string result;
        for (int i = 0; i < 26; i++) equiv[i] = 'a' + i;
        for (int i = 0; i < size(s1); i++){
            char toReplace = max(equiv[s1[i] - 'a'], equiv[s2[i] - 'a']);
            char replaceWith = min(equiv[s1[i] - 'a'], equiv[s2[i] - 'a']);
            for (int i = 0; i < 26; i++) {
                if (equiv[i] == toReplace) equiv[i] = replaceWith;
            }
        }
        for (char ch : baseStr) result += equiv[ch - 'a'];
        return result;
    }
};
