class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long low = 1;
        for (int d = 1; d <= 16; d++) {
            long long high = low * 10 - 1;
            if (low > n) break;
            long long actualHigh = min(high, n);
            long long count = actualHigh - low + 1;
            int commasPerNumber = (d - 1) / 3;
            total += count * (long long)commasPerNumber;
            low = high + 1;
        }
        return total;
    }
};