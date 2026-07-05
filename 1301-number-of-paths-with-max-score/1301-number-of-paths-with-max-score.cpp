class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        vector<vector<int>> max_sum(n, vector<int>(n, -1));
        vector<vector<int>> count(n, vector<int>(n, 0));
        
        max_sum[n - 1][n - 1] = 0;
        count[n - 1][n - 1] = 1;
        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if (board[r][c] == 'X' || (r == n - 1 && c == n - 1)) continue;
                
                int current_val = (board[r][c] == 'E') ? 0 : (board[r][c] - '0');
                
                int dr[] = {1, 0, 1};
                int dc[] = {0, 1, 1};
                
                for (int i = 0; i < 3; ++i) {
                    int nr = r + dr[i], nc = c + dc[i];
                    if (nr < n && nc < n && max_sum[nr][nc] != -1) {
                        int new_sum = max_sum[nr][nc] + current_val;
                        if (new_sum > max_sum[r][c]) {
                            max_sum[r][c] = new_sum;
                            count[r][c] = count[nr][nc];
                        } else if (new_sum == max_sum[r][c]) {
                            count[r][c] = (count[r][c] + count[nr][nc]) % MOD;
                        }
                    }
                }
            }
        }
        
        if (max_sum[0][0] == -1) return {0, 0};
        return {max_sum[0][0], count[0][0]};
    }
};