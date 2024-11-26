class Solution {
public:
    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr) {
        long long max_so_far = arr[0];
        long long max_ending_here = arr[0];
        long long min_ending_here = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < 0) {
                swap(max_ending_here, min_ending_here);
            }

            max_ending_here = max((long long)arr[i], max_ending_here * arr[i]);
            min_ending_here = min((long long)arr[i], min_ending_here * arr[i]);

            max_so_far = max(max_so_far, max_ending_here);
        }

        return max_so_far;
}
};
