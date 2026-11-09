class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> freeServers;
        for (int i = 0; i < k; i++) freeServers.insert(i);

        // min-heap of (finish time, server id)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> busy;
        vector<int> count(k, 0);

        for (int i = 0; i < (int)arrival.size(); i++) {
            // release servers that have finished by this arrival time
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                freeServers.insert(busy.top().second);
                busy.pop();
            }

            if (freeServers.empty()) continue;  // request dropped

            // first free server with id >= i % k, else wrap around
            auto it = freeServers.lower_bound(i % k);
            if (it == freeServers.end()) it = freeServers.begin();

            int id = *it;
            freeServers.erase(it);
            count[id]++;
            busy.push({arrival[i] + load[i], id});
        }

        int mx = *max_element(count.begin(), count.end());
        vector<int> ans;
        for (int i = 0; i < k; i++)
            if (count[i] == mx) ans.push_back(i);
        return ans;
    }
};