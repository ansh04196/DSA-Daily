class Solution {
public:
    static constexpr int MOD = 1000000007;
    int mul(int x, long long y){
        int res = 1, mul = x;
        while (y > 0) {
            if (y % 2 == 1) res = (long long)res * mul % MOD;
            mul = (long long)mul * mul % MOD;
            y /= 2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        return (long long)mul(5, (n + 1) / 2) * mul(4, n / 2) % MOD;
    }
};
