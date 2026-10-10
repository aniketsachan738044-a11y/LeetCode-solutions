class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        const int MAXV = 100000;
        vector<long long> cnt(MAXV + 1, 0);
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            cnt[abs(nums1[i] - nums2[i])]++;
        }

        long long k = (long long)k1 + k2;

        for (int v = MAXV; v > 0 && k > 0; v--) {
            if (cnt[v] == 0) continue;
            long long moved = min(cnt[v], k);
            cnt[v] -= moved;
            cnt[v - 1] += moved;
            k -= moved;
        }

        long long ans = 0;
        for (long long v = 1; v <= MAXV; v++) {
            ans += v * v * cnt[v];
        }
        return ans;
    }
};