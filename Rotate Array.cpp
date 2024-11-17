class Solution {
  public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d %= n;
        // First reversing d elements from starting index.
        reverse(arr.begin(), arr.begin() + d);
        // Then reversing the last n-d elements.
        reverse(arr.begin() + d, arr.begin() + n);
        // Finally, reversing the whole array.
        reverse(arr.begin(), arr.begin() + n);
    }
};
