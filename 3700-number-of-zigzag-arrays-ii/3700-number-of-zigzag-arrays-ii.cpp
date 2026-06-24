
class Solution {
    long long MOD = 1e9 + 7;

    // Standard Matrix Multiplication
    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B, int m) {
        vector<vector<long long>> C(2 * m, vector<long long>(2 * m, 0));
        for (int i = 0; i < 2 * m; ++i)
            for (int k = 0; k < 2 * m; ++k)
                if (A[i][k])
                    for (int j = 0; j < 2 * m; ++j)
                        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
        return C;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        if (n == 1) return r - l + 1;
        int m = r - l + 1;
        int size = 2 * m;

        // Transition Matrix: 
        // First m states: "Down" (next element must be < current)
        // Next m states: "Up" (next element must be > current)
        vector<vector<long long>> T(size, vector<long long>(size, 0));

        for (int i = 0; i < m; ++i) { // Current value is l + i
            for (int j = 0; j < m; ++j) { // Next value is l + j
                if (i == j) continue;
                if (j < i) T[j][i + m] = 1; // From Up to Down
                if (j > i) T[j + m][i] = 1;
            }
        }

        vector<vector<long long>> res(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) res[i][i] = 1;
        long long exp = n - 1;
        while (exp > 0) {
            if (exp % 2 == 1) res = multiply(res, T, m);
            T = multiply(T, T, m);
            exp /= 2;
        }

        
        long long total = 0;
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                total = (total + res[i][j]) % MOD;

        return total;
    }
};