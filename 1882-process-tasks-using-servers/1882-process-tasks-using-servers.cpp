class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        
        // free servers: (weight, index)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> freeQ;
        // busy servers: (finishTime, weight, index)
        priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<>> busyQ;
        
        for (int i = 0; i < n; i++) freeQ.push({servers[i], i});
        
        vector<int> ans(m);
        long long time = 0;
        
        for (int j = 0; j < m; j++) {
            time = max(time, (long long)j);
            
            // if no server is free, jump to the earliest finish time
            if (freeQ.empty()) time = max(time, get<0>(busyQ.top()));
            
            // release all servers that are done by now
            while (!busyQ.empty() && get<0>(busyQ.top()) <= time) {
                auto [f, w, idx] = busyQ.top();
                busyQ.pop();
                freeQ.push({w, idx});
            }
            
            // assign task j to the best free server
            auto [w, idx] = freeQ.top();
            freeQ.pop();
            ans[j] = idx;
            busyQ.push({time + tasks[j], w, idx});
        }
        return ans;
    }
};