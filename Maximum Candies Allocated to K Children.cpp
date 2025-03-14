class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size(), res = 0;
        int lo = 1, hi = 1e9;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            long long count = 0;
            for (int i : candies) count += (i / mid);
            if (count >= k) res = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        return res;
    }
};
