class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int n=arr.size(),total=0;
        
        for(int i=0;i<n;i++){
            total+=(arr[i])*(n-i)*(i+1);
        }
        return total;
    }
};
//GFG POTD solution for 23 July
