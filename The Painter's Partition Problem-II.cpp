class Solution {
  public:
    bool check(vector <int> &arr, int n, int k, long long c)
    {
        int cnt = 0;
        long long t = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > c) return false;
            if (t + arr[i] <= c) {
                t += (long long)arr[i]; 
            } else {
                cnt++;
                t = arr[i];
            }
        }
        cnt++;
        if (cnt <= k) return true;
        return false;
    }
    
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        long long l = 0, r = 10000000000ll;
        while (l < r) {
            long long c = (l + r) / 2;
            if (check(arr, n, k, c)) {
                r = c;
            } else {
                l = c+1;
            }
        }
        return l;        
    }
};
//GFG POTD solution for 14 February
