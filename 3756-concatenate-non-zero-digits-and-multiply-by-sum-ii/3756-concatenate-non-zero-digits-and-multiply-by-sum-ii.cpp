class Solution {
public:
    int M = 1e9 + 7;
    typedef long long ll;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        
        vector<int> nonZeroCount(n, 0);
        vector<ll> numberUpTo(n, 0);
        vector<ll> digitSumUpTo(n, 0);
        vector<ll> pow10(n + 1, 0);

        
        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % M;
        }

        
        nonZeroCount[0] = (s[0] != '0') ? 1 : 0;
        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            nonZeroCount[i] = nonZeroCount[i - 1] + (digit != 0 ? 1 : 0);
        }

        numberUpTo[0] = (s[0] - '0');
        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            if (digit != 0) {
                numberUpTo[i] = (numberUpTo[i - 1] * 10 + digit) % M;
            } else {
                numberUpTo[i] = numberUpTo[i - 1];
            }
        }

        
        digitSumUpTo[0] = (s[0] - '0');
        for (int i = 1; i < n; i++) {
            digitSumUpTo[i] = (digitSumUpTo[i - 1] + (s[i] - '0'));
        }

      
        int q = queries.size();
        vector<int> result(q);
        for (int i = 0; i < q; i++) {
            int L = queries[i][0];
            int R = queries[i][1];

            
            ll sum = digitSumUpTo[R] - (L > 0 ? digitSumUpTo[L - 1] : 0);
            
            
            ll numBefore = (L > 0 ? numberUpTo[L - 1] : 0);
            int k = nonZeroCount[R] - (L > 0 ? nonZeroCount[L - 1] : 0);
            
            ll x = (numberUpTo[R] - (numBefore * pow10[k]) % M + M) % M;

        
            result[i] = (x * (sum % M)) % M;
        }

        return result;
    }
};