class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));

        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                bitset<1024> prev;
                if (i > 0) prev |= dp[i - 1][j];
                if (j > 0) prev |= dp[i][j - 1];

                for (int v = 0; v < 1024; v++) {
                    if (prev[v]) dp[i][j][v ^ grid[i][j]] = 1;
                }
            }
        }

        for (int v = 0; v < 1024; v++) {
            if (dp[m - 1][n - 1][v]) return v;
        }
        return -1; // unreachable
    }
};