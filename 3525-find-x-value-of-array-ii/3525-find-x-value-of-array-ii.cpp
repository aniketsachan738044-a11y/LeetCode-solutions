class Solution {
public:
    int k, n, sz;
    struct Node { int P; int cnt[5][5]; };
    vector<Node> tree;

    inline Node makeLeaf(int val) {
        Node nd;
        nd.P = val % k;
        for (int a = 0; a < k; a++)
            for (int x = 0; x < k; x++)
                nd.cnt[a][x] = ((a * nd.P) % k == x) ? 1 : 0;
        return nd;
    }

    inline Node padLeaf() {
        Node nd;
        nd.P = 1 % k;
        for (int a = 0; a < k; a++)
            for (int x = 0; x < k; x++)
                nd.cnt[a][x] = 0;
        return nd;
    }

    inline Node merge(const Node &L, const Node &R) {
        Node nd;
        nd.P = (L.P * R.P) % k;
        for (int a = 0; a < k; a++) {
            int mid = (a * L.P) % k;
            for (int x = 0; x < k; x++)
                nd.cnt[a][x] = L.cnt[a][x] + R.cnt[mid][x];
        }
        return nd;
    }

    vector<int> resultArray(vector<int>& nums, int k_, vector<vector<int>>& queries) {
        k = k_;
        n = nums.size();
        sz = 1;
        while (sz < n) sz <<= 1;
        tree.assign(2 * sz, Node());

        for (int i = 0; i < sz; i++)
            tree[sz + i] = (i < n) ? makeLeaf(nums[i]) : padLeaf();
        for (int i = sz - 1; i >= 1; i--)
            tree[i] = merge(tree[2*i], tree[2*i+1]);

        vector<int> leftBuf(40), rightBuf(40);
        vector<int> result;
        result.reserve(queries.size());

        for (auto &q : queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];

            // iterative point update
            int pos = index + sz;
            tree[pos] = makeLeaf(value);
            pos >>= 1;
            while (pos >= 1) {
                tree[pos] = merge(tree[2*pos], tree[2*pos+1]);
                pos >>= 1;
            }

            // iterative range query [start, n-1], two-stack decomposition
            // keeps canonical nodes in correct left-to-right merge order
            int l = start + sz, r = (n - 1) + sz + 1;
            int lc = 0, rc = 0;
            while (l < r) {
                if (l & 1) leftBuf[lc++] = l++;
                if (r & 1) { r--; rightBuf[rc++] = r; }
                l >>= 1; r >>= 1;
            }

            int a = 1 % k;
            int ans = 0;
            for (int i = 0; i < lc; i++) {
                Node &nd = tree[leftBuf[i]];
                ans += nd.cnt[a][x];
                a = (a * nd.P) % k;
            }
            for (int i = rc - 1; i >= 0; i--) {
                Node &nd = tree[rightBuf[i]];
                ans += nd.cnt[a][x];
                a = (a * nd.P) % k;
            }
            result.push_back(ans);
        }
        return result;
    }
};