class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(auto it:intervals){
            if(!ans.size() || it[0]>ans.back()[1]){
                ans.push_back(it);
                continue;
            }
            auto element=ans.back();
            ans.pop_back();
            element[1]=fmax(element[1],it[1]);
            ans.push_back(element);
        }
        return ans;
    }
};
//GFG POTD solution for 15 August
