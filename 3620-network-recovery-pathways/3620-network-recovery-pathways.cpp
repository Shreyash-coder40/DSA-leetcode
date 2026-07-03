class Solution {
public:
    bool canReach(int n, const vector<vector<int>>& edges, const vector<bool>& online, long long k, int min_cost_threshold) {
        
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            if (e[2] >= min_cost_threshold) {
                adj[e[0]].push_back({e[1], e[2]});
            }
        }

        
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        if (online[0]) {
            dist[0] = 0;
            pq.push({0, 0});
        }

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;
            if (u == n - 1) return d <= k;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (online[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int low = 0, high = 1e9, ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canReach(online.size(), edges, online, k, mid)) {
                ans = mid;
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};