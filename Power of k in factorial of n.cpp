class Solution {
  public:
    int countPInFactorial(int n, int p) {
        int count = 0;
        while (n) {
            n /= p;
            count += n;
        }
        return count;
    }

    // Prime factorization of k
    map<int, int> primeFactorize(int k) {
        map<int, int> factors;
        for (int i = 2; i * i <= k; ++i) {
            while (k % i == 0) {
                factors[i]++;
                k /= i;
            }
        }
        if (k > 1) {
            factors[k]++;
        }
        return factors;
    }
    int maxKPower(int n, int k) {
        // code here
    map<int, int> kFactors = primeFactorize(k);
        int maxPower = INT_MAX;

        for (map<int, int>::iterator it = kFactors.begin(); it != kFactors.end(); ++it) {
            int p = it->first;
            int e = it->second;
            int powerInFactorial = countPInFactorial(n, p);
            maxPower = min(maxPower, powerInFactorial / e);
        }

        return maxPower;  
    }
};
//GFG POTD solution for 17 July
