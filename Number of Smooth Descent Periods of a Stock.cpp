class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size(), i = 0, j = 0;
        long long res = 0;
        while(i < n){
            j = i;
            while(j + 1 < n && prices[j + 1] == prices[j] - 1) j++;
            long long count = j - i + 1;
            res += (count * (count + 1)) / 2;
            i = j + 1;
        }
        return res;
    }
};
