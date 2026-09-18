class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int,int>> intervals;

        for (int i = 0; i < n; i++) {
            int startChar = s[i] - 'a';
            if (first[startChar] != i) continue; // not a valid start

            int end = last[startChar];
            bool valid = true;
            int j = i;
            while (j <= end) {
                int c = s[j] - 'a';
                if (first[c] < i) { // some char needs to start before i
                    valid = false;
                    break;
                }
                end = max(end, last[c]); // expand end if needed
                j++;
            }

            if (valid) intervals.push_back({i, end});
        }

        // Sort by end position (ascending) for greedy selection
        sort(intervals.begin(), intervals.end(),
             [](const pair<int,int>& a, const pair<int,int>& b) {
                 return a.second < b.second;
             });

        vector<string> res;
        int prevEnd = -1;
        for (auto& [st, en] : intervals) {
            if (st > prevEnd) {
                res.push_back(s.substr(st, en - st + 1));
                prevEnd = en;
            }
        }

        return res;
    }
};