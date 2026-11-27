class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int pmin = INT_MAX;
        for (auto& it : items) pmin = min(pmin, it[1]);

        // value of buying item i for the first time = 1 (itself) + free copies it triggers
        vector<int> val(n);
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (j != i && items[j][0] % items[i][0] == 0) cnt++;
            }
            val[i] = 1 + cnt;
        }

        // 0/1 knapsack: each item type is "first-bought" at most once
        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; i++) {
            int p = items[i][1];
            for (int b = budget; b >= p; b--) {
                dp[b] = max(dp[b], dp[b - p] + val[i]);
            }
        }

        // leftover money buys extra copies of the cheapest item (1 copy each, no extra free copies)
        int ans = 0;
        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[b] + (budget - b) / pmin);
        }
        return ans;
    }
};