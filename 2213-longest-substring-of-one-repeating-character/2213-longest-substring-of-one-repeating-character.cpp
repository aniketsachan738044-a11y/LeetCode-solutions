struct Node {
    int pref, suf, best, len;
    char lc, rc;
};

class Solution {
public:
    vector<Node> tree;
    string s;

    Node merge(const Node& a, const Node& b) {
        Node res;
        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        res.pref = a.pref;
        if (a.pref == a.len && a.rc == b.lc) res.pref += b.pref;

        res.suf = b.suf;
        if (b.suf == b.len && a.rc == b.lc) res.suf += a.suf;

        res.best = max(a.best, b.best);
        if (a.rc == b.lc) res.best = max(res.best, a.suf + b.pref);

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            s[l] = c;
            tree[node] = {1, 1, 1, 1, c, c};
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node, l, mid, idx, c);
        else update(2*node+1, mid+1, r, idx, c);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = s;
        int n = s.size();
        tree.assign(4 * n, Node());
        build(1, 0, n - 1);

        int k = queryIndices.size();
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].best;
        }
        return ans;
    }
};