class Solution {
public:
    static constexpr int MOD = 1000000007;
    int lengthAfterTransformations(string s, int t) {
        int res = 0;
        vector<int> cnt(26);
        for (char ch : s) ++cnt[ch - 'a'];
        for (int round = 0; round < t; ++round) {
            vector<int> nxt(26);
            nxt[0] = cnt[25];
            nxt[1] = (cnt[25] + cnt[0]) % MOD;
            for (int i = 2; i < 26; ++i) nxt[i] = cnt[i - 1];
            cnt = move(nxt);
        }
        for (int i = 0; i < 26; ++i) res = (res + cnt[i]) % MOD;
        return res;
    }

};
