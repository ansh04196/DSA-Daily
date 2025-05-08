
// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n==2){
            return arr[1] + (arr[1]-arr[0]);
        }
        int diff1 = arr[1] - arr[0];
        int diff2 = arr[2] - arr[1];
        int d = min(diff1, diff2);
        for(int i=0;i<n-1;i++){
            int diff = arr[i+1] - arr[i];
            if(d != diff){
                return arr[i+1] - d;
            }
        }
        return arr[n-1] + d;
    }
};


//GFG POTD solution for 08 May
