class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s)
    {
        //dp[] array to store sum till ith index.
        long long dp[s.size()];
        dp[0]=int(s[0]-'0');
        long long res=0, p=1000000007;
        res=dp[0]; 
        
        //iterating over all the digits.
        for(int i=1;i<s.length();i++)
        {
            //getting the integer value of current digit from string.
            int cur_digit=(int)(s[i]-'0');
            
            //storing [current digit*(i+1)+dp[i-1]*10] at dp[i].
            dp[i]=(((i+1)*(cur_digit))%p+(dp[i-1]*10)%p)%p; 
            
            //res stores the sum of all values in dp[].
            res = (res+dp[i])%p;                            
        }
        //returning the result.
        return res;
    }
};
