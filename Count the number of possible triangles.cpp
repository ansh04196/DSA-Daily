class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        int n = arr.size(); // Get the size of the array

        // Sorting the input array.
        sort(arr.begin(), arr.end());

        int count = 0;

        // Traversing the array.
        for (int i = 0; i < n - 2; ++i) {
            // Storing the third index starting from ith index in k.
            int k = i + 2;

             for (int j = i + 1; j < n; ++j) {
                
                while (k < n && arr[i] + arr[j] > arr[k])
                    ++k;

                // Incrementing the count of triangles.
                if (k > j)
                    count += k - j - 1;
            }
        }
        // Returning the count of triangles.
        return count;
    }
};
