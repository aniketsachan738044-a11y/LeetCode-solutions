class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
            suffixSum[i] = suffixSum[i + 1] + piles[i];

        // dp[i][M] = max stones current player can get starting at pile i with given M
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        function<int(int,int)> solve = [&](int i, int M) -> int {
            if (i >= n) return 0;
            if (i + 2 * M >= n) return suffixSum[i]; // take everything left

            if (dp[i][M] != -1) return dp[i][M];

            int best = 0;
            for (int x = 1; x <= 2 * M; x++) {
                if (i + x > n) break;
                int opponent = solve(i + x, max(M, x));
                int mine = suffixSum[i] - opponent;
                best = max(best, mine);
            }
            return dp[i][M] = best;
        };

        return solve(0, 1);
    }
};