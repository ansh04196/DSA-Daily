class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // Initialize two pointers, lo and hi, at the start
        // and end of the array
        int lo = 0, hi = arr.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            // If key found, return the index
            if (arr[mid] == key)
                return mid;

            // If Left half is sorted
            if (arr[mid] >= arr[lo]) {

                // If the key lies within this sorted half,
                // move the hi pointer to mid - 1
                if (key >= arr[lo] && key < arr[mid])
                    hi = mid - 1;

                // Otherwise, move the lo pointer to mid + 1
                else
                    lo = mid + 1;
            }

            // If Right half is sorted
            else {

                // If the key lies within this sorted half,
                // move the lo pointer to mid + 1
                if (key > arr[mid] && key <= arr[hi])
                    lo = mid + 1;

                // Otherwise, move the hi pointer to mid - 1
                else
                    hi = mid - 1;
            }
        }

        // Key not found
        return -1;
    }
};
