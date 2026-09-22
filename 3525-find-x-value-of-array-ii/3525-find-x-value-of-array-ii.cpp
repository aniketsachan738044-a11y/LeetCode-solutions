class Solution {
public:
    int k;
    int n;
    struct Node {
        int P = 1;
        int cnt[5][5] = {};
    };
    vector<Node> tree;

    Node makeLeaf(int val) {
        Node nd;
        nd.P = val % k;
        for (int a = 0; a < k; a++)
            for (int x = 0; x < k; x++)
                nd.cnt[a][x] = ((a * nd.P) % k == x) ? 1 : 0;
        return nd;
    }

    Node merge(const Node &L, const Node &R) {
        Node nd;
        nd.P = (L.P * R.P) % k;
        for (int a = 0; a < k; a++) {
            int mid = (a * L.P) % k;
            for (int x = 0; x < k; x++)
                nd.cnt[a][x] = L.cnt[a][x] + R.cnt[mid][x];
        }
        return nd;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) { tree[node] = makeLeaf(nums[l]); return; }
        int mid = (l + r) / 2;
        build(2*node, l, mid, nums);
        build(2*node+1, mid+1, r, nums);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) { tree[node] = makeLeaf(val); return; }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node, l, mid, idx, val);
        else update(2*node+1, mid+1, r, idx, val);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    int query(int node, int l, int r, int ql, int qr, int &a, int x) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) {
            int res = tree[node].cnt[a][x];
            a = (a * tree[node].P) % k;
            return res;
        }
        int mid = (l + r) / 2;
        int res = 0;
        res += query(2*node, l, mid, ql, qr, a, x);
        res += query(2*node+1, mid+1, r, ql, qr, a, x);
        return res;
    }

    vector<int> resultArray(vector<int>& nums, int k_, vector<vector<int>>& queries) {
        k = k_;
        n = nums.size();
        tree.assign(4 * n, Node());
        build(1, 0, n - 1, nums);

        vector<int> result;
        result.reserve(queries.size());
        for (auto &q : queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];
            update(1, 0, n - 1, index, value);
            int a = 1 % k;   // fix: valid residues are only 0..k-1, so the identity must be reduced mod k
            int ans = query(1, 0, n - 1, start, n - 1, a, x);
            result.push_back(ans);
        }
        return result;
    }
};