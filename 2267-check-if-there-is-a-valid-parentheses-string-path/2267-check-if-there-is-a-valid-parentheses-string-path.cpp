class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if ((m + n - 1) % 2 || grid[0][0] == ')' || grid[m-1][n-1] == '(')
            return false;

        // dp[i][j][b] = true if we can reach (i, j) with balance b
        vector<vector<bitset<201>>> dp(m, vector<bitset<201>>(n));
        dp[0][0][1] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                bitset<201> cur;
                if (i > 0) cur |= dp[i-1][j];
                if (j > 0) cur |= dp[i][j-1];

                if (grid[i][j] == '(') cur <<= 1;   // balance + 1
                else cur >>= 1;                     // balance - 1 (balance 0 falls off, so it is invalid)

                dp[i][j] = cur;
            }
        }
        return dp[m-1][n-1][0];
    }
};