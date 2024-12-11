class Solution {
  public:
    // Function to count the number of occurrences of a given number (target) in a
    // vector.
    int countFreq(vector<int>& arr, int target) {
        // Using lower_bound and upper_bound to count occurrences of target
        auto low = lower_bound(arr.begin(), arr.end(), target);

        // If element is not present, return 0
        if (low == arr.end() || *low != target)
            return 0;

        // Get the index of the last occurrence of target
        auto high = upper_bound(low, arr.end(), target);

        // Return the count of occurrences
        return high - low;
    }
};
