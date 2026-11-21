class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);

        vector<int> newPar(parent), prev(n, -1), order;
        order.reserve(n);
        int last[26];
        fill(last, last + 26, -1);

        // (node, isExit)
        vector<pair<int, bool>> st;
        st.push_back({0, false});
        while (!st.empty()) {
            auto [x, exiting] = st.back();
            st.pop_back();
            int c = s[x] - 'a';
            if (exiting) {
                last[c] = prev[x];
                continue;
            }
            if (last[c] != -1) newPar[x] = last[c];
            prev[x] = last[c];
            last[c] = x;
            order.push_back(x);
            st.push_back({x, true});
            for (int ch : children[x]) st.push_back({ch, false});
        }

        vector<int> ans(n, 1);
        for (int i = n - 1; i >= 1; i--) {
            int x = order[i];
            if (newPar[x] != -1) ans[newPar[x]] += ans[x];
        }
        return ans;
    }
};