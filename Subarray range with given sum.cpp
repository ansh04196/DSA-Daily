class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // using map to store the prefix sum which has appeared already.
        unordered_map<int, int> map;
        int n = arr.size();

        int curr_sum = 0;
        int count = 0;
        unordered_map<int, int>::iterator x;

        // iterating over the array elements.
        for (int i = 0; i < n; i++) {
            // storing prefix sum which is sum of elements till current element.
            curr_sum = curr_sum + arr[i];

            // checking if sum up to current element is equal to the given sum.
            if (curr_sum == tar) {
                // updating the counter.
                count++;
            }
            // if map contains (curr_sum - sum) i.e. difference of current and
            // given sum, it means there is a subarray with sum of elements
            // equal to sum given.
            x = map.find(curr_sum - tar);
            if (x != map.end())
                // adding number of times (curr_sum - sum) has
                // appeared in map to the counter.
                count += x->second;

            // storing the prefix sum in map.
            map[curr_sum]++;
        }
        // returning the count of subarrays.
        return count;
    }
};
