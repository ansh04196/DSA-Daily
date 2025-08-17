class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (n < k) return 0.0;
        if (!k || n >= k - 1 + maxPts) return 1.0;
        double windowSum = 1.0, res = 0.0;
        vector<double> dp(maxPts, 0.0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++){
            double prob = windowSum / maxPts;
            if (i < k) windowSum += prob;
            else res += prob;
            if (i >= maxPts) windowSum -= dp[i % maxPts];
            dp[i % maxPts] = prob;
        }
        return res;
    }
};
