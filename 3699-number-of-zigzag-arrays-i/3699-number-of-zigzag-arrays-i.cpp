class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int MOD = 1e9 + 7;
        
        vector<vector<int>> dp0(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> dp1(n + 1, vector<int>(m + 1, 0));
        
        for (int j = 1; j <= m; ++j) {
            dp0[1][j] = 1;
            dp1[1][j] = 1;
        }
        
        for (int i = 1; i < n; ++i) {
            vector<int> pref0(m + 2, 0);
            vector<int> pref1(m + 2, 0);
            for (int j = 1; j <= m; ++j) {
                pref0[j] = (pref0[j - 1] + dp0[i][j]) % MOD;
                pref1[j] = (pref1[j - 1] + dp1[i][j]) % MOD;
            }
            
            for (int y = 1; y <= m; ++y) {
                dp0[i + 1][y] = pref1[y - 1];
                dp1[i + 1][y] = (pref0[m] - pref0[y] + MOD) % MOD;
            }
        }
        
        int ans = 0;
        for (int j = 1; j <= m; ++j) {
            ans = (ans + dp0[n][j]) % MOD;
            ans = (ans + dp1[n][j]) % MOD;
        }
        
        return ans;
    }
};