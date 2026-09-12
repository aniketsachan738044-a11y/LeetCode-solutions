class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b){
            return intervals[a][1] < intervals[b][1];
        });

        vector<long long> L(n), R(n), W(n);
        vector<int> Idx(n);
        for (int i = 0; i < n; i++) {
            int oi = order[i];
            L[i] = intervals[oi][0];
            R[i] = intervals[oi][1];
            W[i] = intervals[oi][2];
            Idx[i] = oi;
        }

        vector<int> cntBefore(n);
        for (int p = 0; p < n; p++) {
            int lo = 0, hi = p;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (R[mid] < L[p]) lo = mid + 1; else hi = mid;
            }
            cntBefore[p] = lo;
        }

        struct Result {
            long long score = 0;
            vector<int> indices;
        };

        auto pickBetter = [](const Result &a, const Result &b) {
            if (a.score != b.score) return a.score > b.score ? a : b;
            size_t m = min(a.indices.size(), b.indices.size());
            for (size_t i = 0; i < m; i++) {
                if (a.indices[i] != b.indices[i])
                    return a.indices[i] < b.indices[i] ? a : b;
            }
            return a.indices.size() <= b.indices.size() ? a : b;
        };

        vector<vector<Result>> F(n + 1, vector<Result>(5));

        for (int i = 1; i <= n; i++) {
            int p = i - 1;
            F[i][0] = Result{0, {}};
            for (int k = 1; k <= 4; k++) {
                Result skip = F[i-1][k];
                int c = cntBefore[p];
                Result base = F[c][k-1];
                Result take;
                take.score = base.score + W[p];
                take.indices = base.indices;
                auto it = lower_bound(take.indices.begin(), take.indices.end(), Idx[p]);
                take.indices.insert(it, Idx[p]);

                F[i][k] = pickBetter(skip, take);
            }
        }

        return F[n][4].indices;
    }
};