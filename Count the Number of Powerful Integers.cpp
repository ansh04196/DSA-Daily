class Solution {
public:
    vector<vector<long long>> dp;
    long long helper(string &num, string &s, bool tight, int limit, int i){
        if (i == num.size()) return 1;
        if (dp[i][tight] != -1) return dp[i][tight];
        int l = limit;
        if (tight && (num[i] - '0') <= limit) l = num[i] - '0';
        long long res = 0;
        for (int j = 0; j <= l; j++){
            if (i >= (num.size() - s.size())){
                if (!tight) return 1;
                else if (stoll(num.substr(i)) >= stoll(s)) return 1;
            }
            else{
                bool newTight = (tight && j == (num[i] - '0'));
                res += helper(num, s, newTight, limit, i + 1);
            }
        }
        return dp[i][tight] = res;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string begin = to_string(start - 1);
        string end = to_string(finish);
        dp.resize(end.size() + 1, vector<long long> (2, -1));
        long long res = helper(end, s, true, limit, 0);
        for (int i = 0; i < dp.size(); i++) fill(dp[i].begin(), dp[i].end(), -1);
        if (begin.size() >= s.size()) res -= helper(begin, s, true, limit, 0);
        return res;
    }
};
