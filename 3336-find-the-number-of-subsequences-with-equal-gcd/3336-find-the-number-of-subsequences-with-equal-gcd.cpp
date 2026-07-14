#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int max_val = 0;
        for (int x : nums) {
            max_val = max(max_val, x);
        }
        
        // dp[g1][g2] stores the number of ways to get seq1 with GCD g1 and seq2 with GCD g2
        // g1 = 0 or g2 = 0 represents an empty subsequence.
        vector<vector<long long>> dp(max_val + 1, vector<long long>(max_val + 1, 0));
        
        // Base case: both subsequences are initially empty
        dp[0][0] = 1;
        
        for (int x : nums) {
            // Copy current dp state to represent the "skip" choice
            vector<vector<long long>> next_dp = dp;
            
            for (int g1 = 0; g1 <= max_val; ++g1) {
                for (int g2 = 0; g2 <= max_val; ++g2) {
                    if (dp[g1][g2] > 0) {
                        
                        // Option 1: Include x in seq1
                        int ng1 = (g1 == 0) ? x : std::gcd(g1, x);
                        next_dp[ng1][g2] = (next_dp[ng1][g2] + dp[g1][g2]) % MOD;
                        
                        // Option 2: Include x in seq2
                        int ng2 = (g2 == 0) ? x : std::gcd(g2, x);
                        next_dp[g1][ng2] = (next_dp[g1][ng2] + dp[g1][g2]) % MOD;
                    }
                }
            }
            dp = next_dp;
        }
        
        long long ans = 0;
        // Sum up all valid states where both subsequences are non-empty and have the same GCD
        for (int g = 1; g <= max_val; ++g) {
            ans = (ans + dp[g][g]) % MOD;
        }
        
        return ans;
    }
};