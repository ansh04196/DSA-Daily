class Solution {
public:
    int getLPSLength(string &s) {
        int n = s.size();
        if (n == 0) return 0;

        vector<int> lps(n, 0);
        int len = 0; // Length of the previous longest proper prefix suffix

        for (int i = 1; i < n; i++) {
            while (len > 0 && s[i] != s[len]) {
                len = lps[len - 1];
            }
            if (s[i] == s[len]) {
                len++;
            }
            lps[i] = len;
        }
        
        return lps[n - 1];
    }
};
//GFG POTD solution for 08 August
