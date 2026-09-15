class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Precompute palindrome table: isPal[i][j] = true if s[i..j] is a palindrome
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i < 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        // dp[i] = max substrings selected from prefix s[0..i-1]
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1]; // skip using s[i-1]

            // Only need to try lengths k and k+1 ending at i
            for (int len : {k, k + 1}) {
                int start = i - len;
                if (start >= 0 && isPal[start][i - 1]) {
                    dp[i] = max(dp[i], dp[start] + 1);
                }
            }
        }

        return dp[n];
    }
};