class Solution {
  public:
    // Function to return the count of number of elements in the union of two arrays.
    int findUnion(vector<int> a, vector<int> b) {
        // Using unordered_set to store the elements.
        unordered_set<int> s;

        // Insert all the elements of the first array into the set.
        for (int i = 0; i < a.size(); i++)
            s.insert(a[i]);

        // Insert all the elements of the second array into the set.
        // Set does not contain duplicates.
        for (int i = 0; i < b.size(); i++)
            s.insert(b[i]);

        // Returning the size of the set which is the total number
        // of elements in the union of both arrays.
        return s.size();
    }
};
