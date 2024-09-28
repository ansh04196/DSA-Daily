class Solution {
  public:
    // Function to calculate the total count of elements when divided by k.
    int totalCount(int k, vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        // iterating over all the elements.
        for (int i = 0; i < n; i++) {
            // if element is divisible by k, adding quotient to count.
            if (arr[i] % k == 0) {
                count += arr[i] / k;
            } else {
                // if not divisible, adding quotient + 1 to count.
                count += (arr[i] / k + 1);
            }
            // increasing count by 1 if element is 0.
            if (arr[i] == 0) {
                count++;
            }
        }
        // returning total count.
        return count;
    }
};
