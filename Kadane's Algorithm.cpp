class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int ans=INT_MIN;
        int  temp=0;
        for(int i:arr){
            temp+=i;
            ans=max(ans,temp);
            if(temp<0)
             temp=0;
        }
        return ans;
    }
};
