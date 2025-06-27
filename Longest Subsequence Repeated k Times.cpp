class Solution {
public:
    bool isKRepeatedSubsequence(const string& s, const string& t, int k) {
        int n = s.size(), m = t.size(), pos = 0, matched = 0;
        for (char ch : s) {
            if (ch == t[pos]) {
                pos++;
                if (pos == m) {
                    pos = 0;
                    matched++;
                    if (matched == k) return true;
                }
            }
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26);
        vector<char> candidate;
        queue<string> q;
        string ans;
        for (char ch : s) freq[ch - 'a']++;
        for (int i = 25; i >= 0; i--) {
            if (freq[i] >= k) candidate.push_back('a' + i);
        }
        for (char ch : candidate) q.push(string(1, ch));
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            if (curr.size() > ans.size()) ans = curr;
            for (char ch : candidate) {
                string next = curr + ch;
                if (isKRepeatedSubsequence(s, next, k)) q.push(next);
            }
        }
        return ans;
    }
};
