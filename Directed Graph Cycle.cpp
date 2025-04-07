
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        vector<int> degree(V);
        queue<int> qu;
        int count = 0;
        
        for(auto &i : edges) {
            int u = i[0], v = i[1];
            if(u == v) return true;
            degree[v]++;
            adj[u].push_back(v);
        }
        
        for(int i = 0; i < V; i++) {
            if(degree[i] == 0) qu.push(i), count++;
        }
        
        
        while(!qu.empty()) {
            int curr = qu.front();
            qu.pop();
            
            for(auto i : adj[curr]) {
                degree[i]--;
                if(degree[i] == 0) {
                    qu.push(i);
                    count++;
                }
            }
        }
        
        return (count < V);
    }
};


//GFG POTD solution for 07 April
