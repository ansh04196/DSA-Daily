class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        const int N = 1e5 + 2;
        vector<int> freq(N, 0), sweep(N, 0);
        int mini = N, maxi = 0, res = 0, count = 0;
        for (int i : nums){
            freq[i]++;
            const int minimum = max(1, i - k);
            const int maximum = min(i + k + 1, N - 1);
            sweep[minimum]++;
            sweep[maximum]--;
            mini = min(mini, minimum);
            maxi = max(maxi, maximum);
        }
        for (int i = mini; i <= maxi; i++){
            count += sweep[i];
            res = max(res, freq[i] + min(count - freq[i], numOperations));
        }
        return res;
    }
};
