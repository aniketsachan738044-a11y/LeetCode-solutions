class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stoneValue[i];

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // len = length of subarray, process increasing lengths
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                int best = 0;
                for (int k = i; k < j; k++) {
                    int leftSum  = prefix[k + 1] - prefix[i];
                    int rightSum = prefix[j + 1] - prefix[k + 1];

                    if (leftSum < rightSum)
                        best = max(best, dp[i][k] + leftSum);
                    else if (leftSum > rightSum)
                        best = max(best, dp[k + 1][j] + rightSum);
                    else
                        best = max(best, max(dp[i][k], dp[k + 1][j]) + leftSum);
                }
                dp[i][j] = best;
            }
        }
        return dp[0][n - 1];
    }
};