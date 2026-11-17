class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        // cost[i][j] = min changes to make s[i..j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;
                    int m = len / d, changes = 0;
                    for (int r = 0; r < d; r++) {
                        for (int a = 0, b = m - 1; a < b; a++, b--) {
                            if (s[i + r + a * d] != s[i + r + b * d]) changes++;
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // dp[p][i] = min changes to split the first i characters into p parts
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;
        for (int p = 1; p <= k; p++) {
            for (int i = 2 * p; i <= n; i++) {
                for (int j = 2 * (p - 1); j <= i - 2; j++) {
                    if (dp[p - 1][j] == INF || cost[j][i - 1] == INF) continue;
                    dp[p][i] = min(dp[p][i], dp[p - 1][j] + cost[j][i - 1]);
                }
            }
        }
        return dp[k][n];
    }
};