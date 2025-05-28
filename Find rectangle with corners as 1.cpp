class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        vector<pair<int,int>>v;set<pair<int,int>>s;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]) {v.push_back({i,j});s.insert({i,j});}
            }
        }
        for(int i=0;i<v.size();i++)
        {
            for(int j=i+1;j<v.size();j++)
            {
                int x1=v[i].first,y1=v[i].second;
                int x2=v[j].first,y2=v[j].second;
                int xdiff=x2-x1;int ydiff=y2-y1;
                if(s.find({x2,y1})!=s.end() && s.find({x1,y2})!=s.end() && xdiff>0 && ydiff>0) return true;
            }
        }
        return false;
    }
};
//GFG POTD solution for 28 May
