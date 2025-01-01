class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int ans=0;
        for(auto x : arr){
            sum+=x;
            ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};
