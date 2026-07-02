class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        // min_lost[i][j] stores minimum health lost to reach (i, j)
        vector<vector<int>> min_lost(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        
        // Starting point cost
        int start_cost = grid[0][0];
        min_lost[0][0] = start_cost;
        dq.push_front({0, 0});
        
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int weight = grid[nr][nc];
                    if (min_lost[r][c] + weight < min_lost[nr][nc]) {
                        min_lost[nr][nc] = min_lost[r][c] + weight;
                        if (weight == 0) dq.push_front({nr, nc});
                        else dq.push_back({nr, nc});
                    }
                }
            }
        }
        
        // Need to arrive with at least 1 health, so lost must be < health
        return min_lost[m - 1][n - 1] < health;
    }
};