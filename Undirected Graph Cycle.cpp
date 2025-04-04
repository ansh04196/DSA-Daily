
class Solution {
  public:
    // bool solve(int i,unordered_map<int,bool> &vis,vector<vector<int>> &adj,vector<int> &parent){
    //     queue<int> q;
    //     q.push(i);
    //     vis[i]=true;
    //     while(!q.empty()){
    //         int a=q.front();
    //         q.pop();
    //         for(auto j:adj[a]){
    //             if(vis[j]==true&&parent[a]!=j){
    //                 return true;
    //             }
    //             else{
    //                 vis[j]=true;
    //                 parent[j]=a;
    //                 q.push(j);
    //             }
    //         }
    //     }
    //     return false;
    // }
    bool iscuclic(int i,unordered_map<int,bool> &vis,vector<vector<int>> &adj,int parent){
        vis[i]=true;
        for(auto j:adj[i]){
            if(!vis[j]){
                bool cycle=iscuclic(j,vis,adj,i);
                if(cycle){
                    return true;
                }
            }
            else if(j!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,bool> vis;
        vector<vector<int>> adj(V);
        vector<int> parent(V,-1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                // if(solve(i,vis,adj,parent)){
                //     return true;
                // }
                if(iscuclic(i,vis,adj,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};


//GFG POTD solution for 04 April
