class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        int arr2[1000001] = {0};
        int count = 0;
        int maximum = -1;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            arr2[arr[i]]++;
            maximum = max(maximum, arr[i]);
        }
        for (int i = 0; i <= maximum; i++) {
            if (arr2[i] >= 1) {
                count++;
            } else {
                ans = max(ans, count);
                count = 0;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
