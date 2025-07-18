class Solution {
  public:
    int lcmTriplets(int n) {
        if (n < 3) {
            // Not enough numbers to form a triplet
            return n;
        }
    
        if (n % 2 != 0) {
            // If n is odd: use n, n-1, n-2
            return n * (n - 1) * (n - 2);
        }
    
        if (__gcd(n, n - 3) == 1) {
            // Even n, but coprime with n-3: use n, n-1, n-3
            return n * (n - 1) * (n - 3);
        }
    
        // Even n and not coprime with n-3: use n-1, n-2, n-3
        return (n - 1) * (n - 2) * (n - 3);
    }
};
//GFG POTD solution for 18 July
