class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> q, r, d;
        for (int i = 0; i < s.length(); i++) {
            q.push(i);
            if (s[i] == 'R') r.push(i);
            else d.push(i);
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            // banned senator: skip, he loses his turn
            if (s[cur] == 'X') continue;

            if (s[cur] == 'R') {
                if (d.empty()) return "Radiant";
                s[d.front()] = 'X';   // ban the next Dire senator
                d.pop();
                r.pop();              // move this Radiant to the back
                r.push(cur);
                q.push(cur);
            } else {
                if (r.empty()) return "Dire";
                s[r.front()] = 'X';   // ban the next Radiant senator
                r.pop();
                d.pop();              // move this Dire to the back
                d.push(cur);
                q.push(cur);
            }
        }
        return "";
    }
};