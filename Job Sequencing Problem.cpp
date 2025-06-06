
// User Template For C++

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &arr, vector<int> &profit) {
        int n = arr.size();
        vector<pair<int, int>> p;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            p.push_back({profit[i], arr[i]});
            maxi = max(maxi, arr[i]);
        }
        sort(p.rbegin(), p.rend());
        set<int> s;
        for (int i = 1; i <= maxi; i++) {
            s.insert(i);
        }
        int sum = 0, cnt = 0;
        for (int i = 0; i < p.size(); i++) {
            if (s.empty()) break;
            auto it = s.upper_bound(p[i].second);
            if (it != s.begin()) {
                it--;
                sum += p[i].first;
                cnt++;
                s.erase(it);
            }
        }
        return {cnt, sum};
    }
};

//GFG POTD solution for 29 March
