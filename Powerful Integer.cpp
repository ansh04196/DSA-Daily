class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& in, int k) {
        // code here
           map<int , pair<int,int>> mp;

        

        for(auto &x : in){

            mp[x[0]].first += 1;

            mp[x[1]].second -= 1;

        }

        

        int ans = -1, cnt = 0;

        

        

        for(auto &x : mp){

            

             cnt += x.second.first;

             

             if(cnt >= k){

                 ans = x.first;

             }

             

             cnt += x.second.second;

        }

        

        

        return ans;

        
    }
};
//GFG POTD solution for 31 July
