class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        vector<pair<int, int>> sorted_nodes(n);
        for (int i = 0; i < n; ++i) {
            sorted_nodes[i] = {nums[i], i};
        }
        sort(sorted_nodes.begin(), sorted_nodes.end());

        
        vector<int> parent(n);
        int right = 0;
        for (int i = 0; i < n; ++i) {
            while (right < n && sorted_nodes[right].first - sorted_nodes[i].first <= maxDiff) {
                right++;
            }
            parent[i] = right - 1;
        }

       
        int max_log = 18; 
        vector<vector<int>> up(n, vector<int>(max_log, -1));
        for (int i = 0; i < n; ++i) {
            up[i][0] = parent[i];
        }

        for (int k = 1; k < max_log; ++k) {
            for (int i = 0; i < n; ++i) {
                if (up[i][k - 1] != -1) {
                    up[i][k] = up[up[i][k - 1]][k - 1];
                }
            }
        }

       
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) pos[sorted_nodes[i].second] = i;

        
        vector<int> results;
        for (auto& q : queries) {
            int u = pos[q[0]], v = pos[q[1]];
            if (u == v) {
                results.push_back(0);
                continue;
            }
           
            if (u > v) swap(u, v);

            int jumps = 0;
            for (int k = max_log - 1; k >= 0; --k) {
                if (up[u][k] != -1 && up[u][k] < v) {
                    u = up[u][k];
                    jumps += (1 << k);
                }
            }

            
            if (parent[u] >= v) {
                results.push_back(jumps + 1);
            } else {
                results.push_back(-1);
            }
        }
        return results;
    }
};