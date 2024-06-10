class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &a, vector<int> &b) {

        vector<pair<int, int>> diff;
        for (int i = 0; i < n; i++)
            diff.push_back({abs(a[i] - b[i]), i});
        sort(diff.rbegin(), diff.rend());
        
        long long ans = 0;
        for (auto it : diff) {
            int i = it.second;
            if (x==0) {
                ans+=b[i];
                y--;
            }
            else if (y == 0) {
                ans += a[i];
                x--;
            }
            else {
                if (a[i] > b[i]) {
                    ans += a[i];
                    x--;
                }
                else {
                    ans += b[i];
                    y--;
                }
            }
        }
        return ans;
    }
};
