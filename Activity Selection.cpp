
class Solution {
  public:
    int activitySelection(vector<int> &st, vector<int> &fi) {
        vector<pair<int,int>>vec;
        for(int i=0;i<fi.size();i++){
            vec.push_back({st[i],fi[i]});
        }
        sort(vec.begin(),vec.end(),[&](pair<int,int>&a,pair<int,int>&b){
            return a.second < b.second;
        });
        int ans = 1;
        int prev = vec[0].second;;
        for(int i=1;i<vec.size();i++){
            if(prev < vec[i].first){
                prev = vec[i].second;
                ans++;
            }
        }
        return ans;
    }
};


//GFG POTD solution for 28 March
