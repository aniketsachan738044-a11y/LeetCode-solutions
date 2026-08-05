class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }
        
        // Step 1: find all suspicious methods reachable from k
        vector<bool> suspicious(n, false);
        suspicious[k] = true;
        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }
        
        // Step 2: check if any non-suspicious method invokes a suspicious one
        for (auto& inv : invocations) {
            int a = inv[0], b = inv[1];
            if (!suspicious[a] && suspicious[b]) {
                // Can't remove — return all methods
                vector<int> all(n);
                iota(all.begin(), all.end(), 0);
                return all;
            }
        }
        
        // Step 3: safe to remove — return remaining methods
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) result.push_back(i);
        }
        return result;
    }
};