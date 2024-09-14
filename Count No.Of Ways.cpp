//Back-end complete function template in C++

class Solution
{
    public:
     long long countWays(int n, int k)
    {
         long long dp[n + 1];

         memset(dp, 0, sizeof(dp));

         dp[1] = k;

         long long same = 0, diff = k;

         for (int i = 2; i <= n; i++)
        {
             same = diff;

             diff = dp[i-1] * (k-1);
            diff%=1000000007;

             dp[i] = (same + diff);
            dp[i]%=1000000007;
        }

        //Returning the number of ways for n fences.
        return dp[n];
    }
};
