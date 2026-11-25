class Solution {
public:
    typedef unsigned long long ull;
    static const ull MOD = (1ULL << 61) - 1;

    static ull mulmod(ull a, ull b) {
        __uint128_t t = (__uint128_t)a * b;
        ull r = (ull)(t & MOD) + (ull)(t >> 61);
        if (r >= MOD) r -= MOD;
        return r;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        ull base = rng() % (MOD - 1000) + 500;

        vector<ull> pw(n + 1), pre(n + 1);
        pw[0] = 1;
        pre[0] = 0;
        for (int i = 0; i < n; i++) {
            pw[i + 1] = mulmod(pw[i], base);
            pre[i + 1] = mulmod(pre[i], base) + (ull)nums[i];
            if (pre[i + 1] >= MOD) pre[i + 1] -= MOD;
        }

        auto hasUnique = [&](int L) {
            vector<ull> h;
            h.reserve(n - L + 1);
            for (int i = 0; i + L <= n; i++) {
                ull v = pre[i + L] + MOD - mulmod(pre[i], pw[L]);
                if (v >= MOD) v -= MOD;
                h.push_back(v);
            }
            sort(h.begin(), h.end());
            int m = h.size();
            for (int i = 0; i < m; i++) {
                bool samePrev = (i > 0 && h[i] == h[i - 1]);
                bool sameNext = (i + 1 < m && h[i] == h[i + 1]);
                if (!samePrev && !sameNext) return true;
            }
            return false;
        };

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (hasUnique(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};