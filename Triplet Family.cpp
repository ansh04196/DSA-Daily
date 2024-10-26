class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < n; ++k) {
                    if(i != j && j != k && k != i && arr[i] + arr[j] == arr[k])
                        return true;
                }
            }
        }
        return false;
    }
};
