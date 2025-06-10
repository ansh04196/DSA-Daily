class Solution {
public:
    long long helper(long long n, long long curr){
    // To find amount of numbers with the prefix curr between curr & n;
        long long steps = 0, first = curr, last = curr;
        while(first <= n){
            steps += min(n, last) - first + 1;
            first *= 10;
            last = (last * 10) + 9;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        long long curr = 1;
        k--;
        while(k){
            long long steps = helper(n, curr);
            if (steps <= k) curr++, k -= steps;
            else curr *= 10, k--;
        }
        return curr;
    }
};
