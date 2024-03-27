class Solution {
public:
    // BFS function to count the number of reachable cities within the given threshold
    int bfs(vector<vector<pair<int, int>>>& graph, int start, int threshold) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<bool> visited(graph.size(), false);
        int count = 0;

        while (!q.empty()) {
            // Extract the current node and its distance from the queue
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();

            // Skip if the node has been visited or the distance exceeds the threshold
            if (visited[node] || distance > threshold)
                continue;

            // Mark the node as visited and increment the count
            visited[node] = true;
            count++;

            // Explore neighbors and add them to the queue if not visited
            for (auto neighbor : graph[node]) {
                int next_node = neighbor.first;
                int weight = neighbor.second;
                if (!visited[next_node])
                    q.push({next_node, distance + weight});
            }
        }

        // Return the count of reachable cities within the threshold
        return count;
    }

    // Function to find the city with the smallest number of reachable cities within the threshold
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Create a graph represented as a vector of vectors of pairs
        vector<vector<pair<int, int>>> graph(n);

        // Populate the graph with edges and weights
        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            graph[from].push_back({to, weight});
            graph[to].push_back({from, weight});
        }

        // Initialize variables to track the minimum count and the selected city
        int min_count = INT_MAX;
        int selected_city = -1;

        // Iterate through each city and calculate the count using BFS
        for (int i = 0; i < n; ++i) {
            int count = bfs(graph, i, distanceThreshold);

            // Update the minimum count and selected city if needed
            if (count < min_count || (count == min_count && i > selected_city)) {
                min_count = count;
                selected_city = i;
            }
        }

        // Return the city with the smallest number of reachable cities within the threshold
        return selected_city;
    }
};
