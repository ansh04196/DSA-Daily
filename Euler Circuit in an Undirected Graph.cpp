//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
	vector<bool>used; // vector to keep track of whether an edge has been used
	vector<int>eu,ev; // vectors to store the vertices of each edge
	vector<int>ans; // vector to store the result of the Eulerian circuit

	// Depth-first search function to find the Eulerian circuit
	void dfs(int u, vector<vector<int>>& adj) {
		while (adj[u].size()) { // as long as there are adjacent edges to visit
			int e = adj[u].back(); // get the last adjacent edge
			adj[u].pop_back(); // remove the visited edge from the adjacent list

			if (used[e]) // if the edge has been used, continue to the next iteration
				continue;

			used[e] = true; // mark the edge as used
			dfs(eu[e] ^ ev[e] ^ u, adj); // recursively visit the other vertex of the edge
			ans.push_back(u); // add the current vertex to the result
		}
	}
 	// Function to check if an Eulerian circuit exists
	bool isEularCircuitExist(int v, vector<int>adj[]) {
		set<pair<int,int>>st; // set to store unique edges
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				int u = i;
				int k = adj[i][j];

				if (st.find({u, k}) == st.end() and st.find({k, u}) == st.end()) {
					eu.push_back(u); // add u to the vector eu
					ev.push_back(k); // add k to the vector ev
					st.insert({u, k}); // insert the edge (u, k) to the set
				}
			}
		}

		vector<vector<int>>adj1(v); // create an empty adjacency list
		used.assign(eu.size(), false); // initialize the used vector with false values

		for (int i = 0; i < eu.size(); i++) {
			adj1[eu[i]].push_back(i); // add the index of the edge to the adjacency list of eu[i]
			adj1[ev[i]].push_back(i); // add the index of the edge to the adjacency list of ev[i]
		}

		for (int i = 0; i < v; i++) {
			if (adj1[i].size() & 1) // check if there is an odd number of adjacent edges to a vertex
				return false; // if so, return false
		}

		ans.push_back(0); // add the starting vertex to the result
		dfs(0, adj1); // call the dfs function to find the Eulerian circuit

		if ((int)ans.size() ^ (int)eu.size() + 1) // check if the number of vertices in the result is not equal to the number of edges + 1
			return false; // if so, return false

		return true; // otherwise, return true indicating that an Eulerian circuit exists
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends
