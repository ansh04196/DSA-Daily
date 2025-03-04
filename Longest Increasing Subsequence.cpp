
class Solution {
  public:
    int lis(vector<int>& arr) {
       vector<int>ans;
       
       int n=arr.size();
       for(int i=0;i<n;i++){
           if(ans.empty() || arr[i]>ans.back()) ans.push_back(arr[i]);
           else{
           auto it=lower_bound(ans.begin(),ans.end(),arr[i]);
           int pos=it-ans.begin();
           //cout<<pos<<endl;
           ans[pos]=arr[i];
           }
       }
       return ans.size();
        
    }
};


//GFG POTD solution for 04 March
