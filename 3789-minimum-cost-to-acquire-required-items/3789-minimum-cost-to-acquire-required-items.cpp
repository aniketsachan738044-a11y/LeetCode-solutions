class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;

        // Option A: buy only individual items
        long long optA = n1 * c1 + n2 * c2;

        // Option B: buy min(need1, need2) type-3 items, then cover the
        // leftover of the larger need with the cheaper of its own item or a type-3 item
        long long m = min(n1, n2);
        long long rest = (n1 > n2) ? (n1 - n2) * min(c1, cb)
                                   : (n2 - n1) * min(c2, cb);
        long long optB = m * cb + rest;

        return min(optA, optB);
    }
};