class Solution {
  public:
    // Function to sort an array of 0s, 1s, and 2s
    void sort012(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1, mid = 0;

        // using the Dutch National Flag algorithm
        while (mid <= high) {

            // if the current element is 0, swap it with the element at the low index
            if (arr[mid] == 0)
                swap(arr[mid++], arr[low++]);

            // if the current element is 1, move to the next element
            else if (arr[mid] == 1)
                mid++;

            // if the current element is 2, swap it with the element at the high index
            else
                swap(arr[mid], arr[high--]);
        }
    }
};
