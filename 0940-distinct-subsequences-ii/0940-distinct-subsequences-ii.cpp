class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; // empty subsequence
        vector<int> last(26, -1); // last[c] = index (1-based) of last occurrence

        for (int i = 1; i <= n; i++) {
            int c = s[i - 1] - 'a';
            dp[i] = (2 * dp[i - 1]) % MOD;
            if (last[c] != -1) {
                dp[i] = (dp[i] - dp[last[c] - 1] + MOD) % MOD;
            }
            last[c] = i;
        }

        // subtract 1 for the empty subsequence counted in dp[n]
        return (int)((dp[n] - 1 + MOD) % MOD);
    }
};