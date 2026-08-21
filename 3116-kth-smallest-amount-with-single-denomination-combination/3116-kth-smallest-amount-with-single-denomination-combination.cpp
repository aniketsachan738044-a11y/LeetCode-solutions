class Solution {
public:
    __int128 gcd128(__int128 a, __int128 b) {
        while (b) { a %= b; swap(a, b); }
        return a;
    }

    long long countMultiples(long long x, vector<int>& coins) {
        int n = coins.size();
        long long total = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            __int128 lcm = 1;
            bool overflow = false;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    __int128 g = gcd128(lcm, (__int128)coins[i]);
                    lcm = lcm / g * coins[i];
                    if (lcm > (__int128)x) { overflow = true; break; }
                }
            }
            if (overflow) continue;
            int bits = __builtin_popcount(mask);
            long long cnt = x / (long long)lcm;
            if (bits % 2 == 1) total += cnt;
            else total -= cnt;
        }
        return total;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long lo = 1;
        long long hi = (long long)k * (*min_element(coins.begin(), coins.end()));
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countMultiples(mid, coins) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};