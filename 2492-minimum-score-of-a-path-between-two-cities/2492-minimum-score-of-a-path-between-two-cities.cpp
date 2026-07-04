
class Solution {
public:
    int minScore(int n, std::vector<std::vector<int>>& roads) {
        // Build the adjacency list: vector of vectors of pairs {neighbor, distance}
        std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        // BFS setup
        std::vector<bool> visited(n + 1, false);
        std::queue<int> q;
        
        q.push(1);
        visited[1] = true;
        
        int minScore = INT_MAX;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (const auto& edge : adj[curr]) {
                int neighbor = edge.first;
                int distance = edge.second;

                // Update minScore with the edge distance
                minScore = std::min(minScore, distance);

                // If not visited, add to queue
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return minScore;
    }
};