class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        map <int, int> m;        
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) m[arr[i]] = 1;
        }
        int i = 1;
        while (m[i] == 1) i++;
        return i;   
    }
};
