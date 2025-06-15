class Solution {
  public:
    bool fun(int mid,vector<int>&arr,int k){
        int sum=0;
        for (int num : arr) {
            sum += (num + mid - 1) / mid;
        }
        return sum <= k;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code herearr
        int mxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            mxi=max(mxi,arr[i]);
        }
        
        int low=1;
        int high=mxi;
        int ans=mxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(fun(mid,arr,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return ans;
        
    }
};

//GFG POTD solution for 15 June
