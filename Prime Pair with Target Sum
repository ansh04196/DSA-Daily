class Solution {
  public:
    bool fn(int n) {
        for(int i=2; i*i<=n; i++) {
            if(n%i==0)
                return false;
        }
        return true;
    }
    vector<int> getPrimes(int N) {
        // code here
        for(int i=2; i<=N/2; i++)
            if(fn(i) and fn(N-i))
                return {i, N-i};
        return {-1,-1};
    }
};
