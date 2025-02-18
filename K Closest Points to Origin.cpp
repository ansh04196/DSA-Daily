class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
       priority_queue<pair<int, int>> pq;
        int n=points.size();
        for(int i=0; i<n; i++){
            int x=points[i][0], y=points[i][1];
            int dist=x*x+y*y;
            pq.push({dist, i});
            if(pq.size()>k)
            pq.pop();
        }
        
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return ans;
    }
};

 
