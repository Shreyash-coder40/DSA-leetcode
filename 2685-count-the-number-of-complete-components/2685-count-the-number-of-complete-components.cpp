class Solution {
public:
    void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Step 1: Build the adjacency list and track degrees
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        vector<bool> visited(n, false);
        int completeComponentsCount = 0;

        // Step 2: Traverse the graph to find components
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, adj, visited, component);

                // Step 3: Check if the current component is complete
                int numVertices = component.size();
                bool isComplete = true;

                for (int node : component) {
                    if (degree[node] != numVertices - 1) {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete) {
                    completeComponentsCount++;
                }
            }
        }

        return completeComponentsCount;
    }
};