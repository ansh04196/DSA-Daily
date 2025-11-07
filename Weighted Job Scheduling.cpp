class Solution {
public:
    static bool check(long long minPower, vector<int> stations, int r, long long k, int n) {
        long long power = accumulate(stations.begin(), stations.begin() + r + 1, 0LL);
        for (int i = 0; i < n; i++) {
            if (power < minPower) {
                long long need = minPower - power;
                if (need > k) return false;
                k -= need;
                stations[min(n - 1, i + r)] += need;
                power += need;
            }
            if (i >= r) power -= stations[i - r];
            if (i + r + 1 < n) power += stations[i + r + 1];
        }
        return true;
    }
    static long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        long long left = 0, right = 1e18, res = 0;
        while (left <= right) {
            long long mid = left + (right-left) / 2;
            if (check(mid, stations, r, k, n)) res = mid, left = mid + 1;
            else right = mid - 1;
        }
        return res;
    }
};
