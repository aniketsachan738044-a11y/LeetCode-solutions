class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ngi(n);
        stack<int> st;
        ngi[n-1] = n;
        st.push(n-1);
        for (int i = n-2; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            ngi[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG++; // safety margin

        // up[p][i] = index reached after 2^p jumps along the ngi chain from i
        vector<vector<int>> up(LOG, vector<int>(n + 1, n));
        for (int i = 0; i < n; i++) up[0][i] = ngi[i];
        for (int p = 1; p < LOG; p++)
            for (int i = 0; i <= n; i++)
                up[p][i] = up[p-1][ up[p-1][i] ];

        vector<int> ans;
        for (int i = 0; i + k <= n; i++) {
            int j = i;
            int mx = arr[i];
            for (int p = LOG - 1; p >= 0; p--) {
                int nxt = up[p][j];
                if (nxt < i + k) {   // still inside window
                    j = nxt;
                    mx = arr[j];
                }
            }
            ans.push_back(mx);
        }
        return ans;
    }
};