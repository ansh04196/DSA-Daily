class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        
        int cnt = 0,n = arr.size(),i = 0 ;
        while(i<n) {
            if(arr[i]!=i+1) {
                cnt++;
                swap(arr[i],arr[arr[i]-1]);
            }
            else i++;
        }
        
        return cnt <= 2;
    }
};
