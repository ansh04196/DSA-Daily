class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int>
            prefixSumIndices; // Maps cumulative sum to its earliest index
        int currentSum = 0, longestLength = 0;

        // Traverse through the array
        for (int i = 0; i < arr.size(); i++) {
            currentSum += arr[i]; // Accumulate the current sum

            // Check if subarray starting from index 0 equals k
            if (currentSum == k)
                longestLength = i + 1;

            // If (currentSum - k) exists in the map, update longestLength
            if (prefixSumIndices.find(currentSum - k) != prefixSumIndices.end()) {
                longestLength =
                    max(longestLength, i - prefixSumIndices[currentSum - k]);
            }

            // Store the current sum in the map if it hasn't been stored yet
            if (prefixSumIndices.find(currentSum) == prefixSumIndices.end())
                prefixSumIndices[currentSum] = i;
        }

        return longestLength; // Return the length of the longest subarray
    }
};
