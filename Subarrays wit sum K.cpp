#include<bits/stdc++.h>
class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> prefixSum;
        int ans=0, currentSum=0;
        prefixSum[0]=1;
        for(int i=0;i<arr.size();i++){
            currentSum+=arr[i];
            
            if(prefixSum.find(currentSum-k)!=prefixSum.end()){
                ans+=prefixSum[currentSum-k];
            }
            prefixSum[currentSum]++;
        }
        return ans;
    }
};
//GFG POTD solution for 30 July
