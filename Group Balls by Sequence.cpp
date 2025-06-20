class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
          int n=arr.size();
        multiset<int>st(arr.begin(),arr.end());
        vector<vector<int>>res;
        while(!st.empty())
        {
            int x=*st.begin();
            vector<int>ans;
            ans.push_back(x);
            st.erase(x);
            while(!st.empty() && *(st.upper_bound(x))==x+1 && ans.size()<k)
            {
               ans.push_back(x+1);
               st.erase(x+1);
               x++;
            }
            res.push_back(ans);
        }
        for(int i=0;i<res.size();i++)
        {
           
            if(res[i].size()!=k)
            {
                return false;
            }
        }
        return true;
    }
};
//GFG POTD solution for 20 June
