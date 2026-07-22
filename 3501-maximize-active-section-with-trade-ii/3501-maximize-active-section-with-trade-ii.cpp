class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int totalOnes = 0;
        for (char c : s) if (c == '1') totalOnes++;

        // Zero groups: gStart[k], gLen[k]
        // gid[i] = index of the most recently completed/current zero group up to position i (-1 if none yet)
        vector<int> gStart, gLen, gid(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') gLen.back()++;
                else { gStart.push_back(i); gLen.push_back(1); }
            }
            gid[i] = (int)gStart.size() - 1;
        }

        int m = gStart.size();
        if (m == 0) return vector<int>(queries.size(), totalOnes);

        // Sums of adjacent zero-group lengths, for sparse table range-max
        int psz = max(m - 1, 0);
        vector<int> pairSum(psz);
        for (int k = 0; k + 1 < m; k++) pairSum[k] = gLen[k] + gLen[k + 1];

        int LOG = 1;
        while ((1 << LOG) <= psz) LOG++;
        vector<vector<int>> sp(LOG, vector<int>(psz));
        if (psz > 0) {
            sp[0] = pairSum;
            for (int k = 1; k < LOG; k++)
                for (int i = 0; i + (1 << k) <= psz; i++)
                    sp[k][i] = max(sp[k - 1][i], sp[k - 1][i + (1 << (k - 1))]);
        }
        auto rangeMax = [&](int l, int r) -> int {
            if (l > r) return -1;
            int len = r - l + 1;
            int k = 31 - __builtin_clz(len);
            return max(sp[k][l], sp[k][r - (1 << k) + 1]);
        };

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int best = totalOnes;

            int gl = gid[l], gr = gid[r];
            bool lIsZero = (s[l] == '0');
            bool rIsZero = (s[r] == '0');

            int leftPart  = lIsZero ? (gStart[gl] + gLen[gl] - l) : -1;
            int rightPart = rIsZero ? (r - gStart[gr] + 1) : -1;

            int firstFull = gl + 1;
            int lastFull  = rIsZero ? gr - 1 : gr;

            if (lIsZero && rIsZero && gl + 1 == gr) {
                best = max(best, totalOnes + leftPart + rightPart);
            } else if (firstFull <= lastFull - 1) {
                best = max(best, totalOnes + rangeMax(firstFull, lastFull - 1));
            }
            if (lIsZero && firstFull <= lastFull) {
                best = max(best, totalOnes + leftPart + gLen[firstFull]);
            }
            if (rIsZero && gl < gr - 1) {
                best = max(best, totalOnes + rightPart + gLen[gr - 1]);
            }

            ans.push_back(best);
        }
        return ans;
    }
};