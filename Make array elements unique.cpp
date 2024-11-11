class Solution {
  public:
    int minIncrements(vector<int> arr) {
        // Code here
        int n = arr.size();
        long long diff = 0;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                arr[i + 1]++;
                diff++;
            }
            if (arr[i] > arr[i + 1])
            {
                diff = diff + (arr[i] - arr[i + 1]) + 1;
                arr[i + 1] = arr[i] + 1;
            }
        }
        return diff;
    }
};
