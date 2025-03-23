class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, 0)));
        // dp[src][dest][0] stores the minimum time between src and dest
        // dp[src][dest][1] stores the number of ways to reach dest from src
        // with the minimum time
        for (auto src = 0; src < n; src++) {
            for (auto dest = 0; dest < n; dest++) {
                if (src != dest) {
                    dp[src][dest][0] = 1e12;
                    dp[src][dest][1] = 0;
                } 
                else {
                    dp[src][dest][0] = 0;
                    dp[src][dest][1] = 1;
                }
            }
        }
        for (auto& road : roads) {
            long long int startNode = road[0], endNode = road[1], travelTime = road[2];
            dp[startNode][endNode][0] = travelTime;
            dp[endNode][startNode][0] = travelTime;
            dp[startNode][endNode][1] = 1;
            dp[endNode][startNode][1] = 1;
        }
        for (auto mid = 0; mid < n; mid++) {
            for (auto src = 0; src < n; src++){
                for (auto dest = 0; dest < n; dest++) {
                    if (src != mid && dest != mid) {
                        long long int newTime = dp[src][mid][0] + dp[mid][dest][0];
                        if (newTime < dp[src][dest][0]) {
                            dp[src][dest][0] = newTime;
                            dp[src][dest][1] = (dp[src][mid][1] * dp[mid][dest][1]) % MOD;
                        } 
                        else if (newTime == dp[src][dest][0]) {
                            dp[src][dest][1] = 
                            (dp[src][dest][1] + dp[src][mid][1] * dp[mid][dest][1]) %    MOD;
                        }
                    }
                }
            }
        }
        return dp[n - 1][0][1];
    }
};
