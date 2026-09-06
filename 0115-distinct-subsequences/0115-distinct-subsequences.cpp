class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (n > m) return 0;
        
        // dp[i][j] = number of distinct subsequences of s[0..i) equal to t[0..j)
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        
        // Empty t can be formed in exactly 1 way (by deleting everything) from any prefix of s
        for (int i = 0; i <= m; i++) dp[i][0] = 1;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // Option 1: don't use s[i-1]
                dp[i][j] = dp[i - 1][j];
                
                // Option 2: use s[i-1] if it matches t[j-1]
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        
        return (int)dp[m][n];
    }
};