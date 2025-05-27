class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long sum = 0, sum1 = 0;
        for (int i = 1; i <= n; i++){
            if (i % m == 0) sum1 += i;
            sum += i;
        }
        long long sum2 = sum - sum1;
        return sum2 - sum1;
    }
};
