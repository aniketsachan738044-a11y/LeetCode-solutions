class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        array<int, 26> cnt{};
        for (char ch : s) cnt[ch - 'a']++;

        vector<int> odd;
        for (int c = 0; c < 26; c++)
            if (cnt[c] % 2 == 1) odd.push_back(c);

        if ((n % 2 == 0 && !odd.empty()) || (n % 2 == 1 && odd.size() != 1))
            return "";

        int midChar = (n % 2 == 1) ? odd[0] : -1;

        array<int, 26> baseAvail{};
        for (int c = 0; c < 26; c++) baseAvail[c] = cnt[c] / 2;

        auto tryPrefix = [&](int i, vector<int>& ans, array<int, 26>& remaining) -> bool {
            ans.assign(n, -1);
            remaining = baseAvail;
            for (int j = 0; j < i; j++) {
                int partner = n - 1 - j;
                int c = target[j] - 'a';
                if (ans[j] != -1) {
                    if (ans[j] != c) return false;
                    continue;
                }
                if (partner == j) {
                    if (c != midChar) return false;
                    ans[j] = c;
                } else {
                    if (remaining[c] <= 0) return false;
                    remaining[c]--;
                    ans[j] = c;
                    if (ans[partner] != -1 && ans[partner] != c) return false;
                    ans[partner] = c;
                }
            }
            return true;
        };

        vector<int> ans;
        array<int, 26> remaining{};

        for (int i = n - 1; i >= 0; i--) {
            if (!tryPrefix(i, ans, remaining)) continue;

            int partner = n - 1 - i;
            int needed = target[i] - 'a';

            if (ans[i] != -1) {
                // Position i was already forced by an earlier mirror constraint.
                // Only usable as a breakpoint if it's already greater than target[i].
                if (ans[i] <= needed) continue;
                // else: fall through and fill the rest below.
            } else if (partner == i) {
                // i is the middle slot, still free.
                if (midChar != -1 && midChar > needed) {
                    ans[i] = midChar;
                } else {
                    continue;
                }
            } else {
                // Free to choose: smallest available char strictly greater than needed.
                int choice = -1;
                for (int c = needed + 1; c < 26; c++) {
                    if (remaining[c] > 0) { choice = c; break; }
                }
                if (choice == -1) continue;
                remaining[choice]--;
                ans[i] = choice;
                ans[partner] = choice;
            }

            // Fill everything else with the smallest available letters.
            for (int j = 0; j < n; j++) {
                if (ans[j] != -1) continue;
                int partner2 = n - 1 - j;
                if (partner2 == j) {
                    ans[j] = midChar;
                } else {
                    int c = -1;
                    for (int k = 0; k < 26; k++)
                        if (remaining[k] > 0) { c = k; break; }
                    remaining[c]--;
                    ans[j] = c;
                    ans[partner2] = c;
                }
            }

            string result(n, ' ');
            for (int j = 0; j < n; j++) result[j] = 'a' + ans[j];
            return result;
        }

        return "";
    }
};