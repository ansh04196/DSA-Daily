class Solution {
public:
    int setBits(int n){
        int res = 0;
        while(n) res += n & 1, n >>= 1;
        return res;
    }
    bool isPrime(int n){
        return (n == 2 or n == 3 or n == 5 or n == 7 or n == 11 or n == 13 or n == 17 or n == 19 or n == 23 or n == 29 or n == 31);
    }
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for (int i = left; i <= right; i++){
            if (isPrime(setBits(i))) res++;
        }
        return res;
    }
};
