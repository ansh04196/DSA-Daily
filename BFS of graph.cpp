
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        queue<int> q;
        q.push(0);
        vector<int> ans;
        int n=adj.size();
        vector<int> vis(n,0);
        vis[0]=1;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(auto it:adj[f]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return ans;
    }
};


//GFG POTD solution for 02 April
