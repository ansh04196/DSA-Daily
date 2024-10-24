class Solution {
  public:
  void shiftAllZeroToLeft(vector<int>&array, int n)
    {
        // Maintain last index with positive value
        int lastSeenNonZero = 0;
     
        for (int index = 0; index < n; index++) 
        {
            // If Element is non-zero
            if (array[index] != 0) 
            {
                // swap current index, with lastSeen non-zero
                swap(array[index], array[lastSeenNonZero]);
     
                // next element will be last seen non-zero
                lastSeenNonZero++;
            }
        }
    }
    // function which pushes all zeros to end of
    // an array.
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
         if (n == 1)
            return arr;
     
        // traverse the array
        for (int i = 0; i < n - 1; i++) {
     
            // if true, perform the required modification
            if ((arr[i] != 0) && (arr[i] == arr[i + 1])) {
     
                // double current index value
                arr[i] = 2 * arr[i];
     
                // put 0 in the next index
                arr[i + 1] = 0;
     
                // increment by 1 so as to move two indexes
                // ahead during loop iteration
                i++;
            }
        }
     
        // push all the zeros at the end of 'arr[]'
        shiftAllZeroToLeft(arr, n);
        
        return arr;
    }
};
