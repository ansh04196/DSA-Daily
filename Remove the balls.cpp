class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        stack<pair<int,int>> st;
        int n = color.size();
        
        for(int i=0;i<n;++i)
        {
            int c = color[i];
            int r = radius[i];
            
            if(!st.empty() && st.top().first == c && st.top().second == r)
                st.pop();
            else
                st.push({c,r});
        }
        
        return st.size();
    }
};
//GFG POTD solution for 11 June
