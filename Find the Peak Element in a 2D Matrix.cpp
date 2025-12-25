class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long n = happiness.size(), sum = 0, times = 0;
        vector<int> arr = happiness;
        sort(arr.begin(), arr.end());
        for (int i = n - 1; i >= n - k; i--, times++) sum += max(0LL, arr[i] - times);
        return sum;
    }
};
