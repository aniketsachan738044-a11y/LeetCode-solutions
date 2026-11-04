class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int m = n - x + 1;
        vector<long long> cost(m);

        multiset<int> lo, hi;
        long long sumLo = 0, sumHi = 0;
        int loSize = (x + 1) / 2;

        auto rebalance = [&]() {
            while ((int)lo.size() > loSize) {
                auto it = prev(lo.end());
                sumLo -= *it;
                sumHi += *it;
                hi.insert(*it);
                lo.erase(it);
            }
            while ((int)lo.size() < loSize && !hi.empty()) {
                auto it = hi.begin();
                sumHi -= *it;
                sumLo += *it;
                lo.insert(*it);
                hi.erase(it);
            }
        };
        auto add = [&](int v) {
            if (lo.empty() || v <= *lo.rbegin()) {
                lo.insert(v);
                sumLo += v;
            } else {
                hi.insert(v);
                sumHi += v;
            }
            rebalance();
        };
        auto remove = [&](int v) {
            if (v <= *lo.rbegin()) {
                lo.erase(lo.find(v));
                sumLo -= v;
            } else {
                hi.erase(hi.find(v));
                sumHi -= v;
            }
            rebalance();
        };

        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) remove(nums[i - x]);
            if (i >= x - 1) {
                long long med = *lo.rbegin();
                cost[i - x + 1] = med * (long long)lo.size() - sumLo
                                + sumHi - med * (long long)hi.size();
            }
        }

        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        for (int i = 0; i <= n; i++) dp[i][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
                if (i >= x && dp[i - x][j - 1] < INF) {
                    dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + cost[i - x]);
                }
            }
        }
        return dp[n][k];
    }
};