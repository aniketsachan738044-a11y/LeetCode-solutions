class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> R(m, vector<long long>(n, 0));
        vector<vector<long long>> D(m, vector<long long>(n, 0));

        // Start at (0,0), which is always empty.
        R[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long r = R[i][j] % MOD;
                long long d = D[i][j] % MOD;
                if (r == 0 && d == 0) continue;

                if (grid[i][j] == 0) {
                    long long total = (r + d) % MOD;
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + total) % MOD;
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + total) % MOD;
                } else {
                    // Entered moving right -> reflected down
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + r) % MOD;
                    // Entered moving down -> reflected right
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + d) % MOD;
                }
            }
        }

        return (R[m - 1][n - 1] + D[m - 1][n - 1]) % MOD;
    }
};