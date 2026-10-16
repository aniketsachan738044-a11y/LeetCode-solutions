class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<long long> s1, s2, lz;

    void apply(int node, int len, long long v) {
        s2[node] += 2 * v * s1[node] + (long long)len * v * v;
        s1[node] += (long long)len * v;
        lz[node] += v;
    }

    void push(int node, int l, int r) {
        if (lz[node]) {
            int m = (l + r) / 2;
            apply(2 * node, m - l + 1, lz[node]);
            apply(2 * node + 1, r - m, lz[node]);
            lz[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(node, r - l + 1, 1);
            return;
        }
        push(node, l, r);
        int m = (l + r) / 2;
        update(2 * node, l, m, ql, qr);
        update(2 * node + 1, m + 1, r, ql, qr);
        s1[node] = s1[2 * node] + s1[2 * node + 1];
        s2[node] = s2[2 * node] + s2[2 * node + 1];
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        s1.assign(4 * n, 0);
        s2.assign(4 * n, 0);
        lz.assign(4 * n, 0);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int j = 0; j < n; j++) {
            update(1, 0, n - 1, last[nums[j]] + 1, j);
            last[nums[j]] = j;
            ans = (ans + s2[1]) % MOD;
        }
        return (int)ans;
    }
};