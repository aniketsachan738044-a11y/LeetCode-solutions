class Solution {
public:
    vector<long long> subsetLcm;
    int n;

    long long findKthSmallest(vector<int>& coins, int k) {
        n = coins.size();
        int total = 1 << n;
        subsetLcm.assign(total, 0);

        // Precompute LCM for every subset once
        for (int mask = 1; mask < total; mask++) {
            int lsb = mask & (-mask);
            int idx = __builtin_ctz(lsb);
            long long prev = subsetLcm[mask ^ lsb];
            if (prev == -1) { subsetLcm[mask] = -1; continue; }
            if (mask == lsb) {
                subsetLcm[mask] = coins[idx];
            } else {
                long long g = __gcd(prev, (long long)coins[idx]);
                long long factor = coins[idx] / g;
                // overflow guard: bail if it exceeds max possible answer
                if (prev > (long long)4e18 / factor) subsetLcm[mask] = -1; // mark invalid
                else subsetLcm[mask] = prev * factor;
            }
        }

        long long lo = 1;
        long long hi = (long long)k * (*min_element(coins.begin(), coins.end()));
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countMultiples(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }

    long long countMultiples(long long x) {
        long long total = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            long long lcm = subsetLcm[mask];
            if (lcm == -1 || lcm > x) continue;
            int bits = __builtin_popcount(mask);
            long long cnt = x / lcm;
            total += (bits % 2 == 1) ? cnt : -cnt;
        }
        return total;
    }
};