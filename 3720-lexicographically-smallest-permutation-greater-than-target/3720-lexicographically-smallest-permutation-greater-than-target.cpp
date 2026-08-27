class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        string result(n, ' ');
        int k = n; // position where matching fails (n if fully matched)

        for (int i = 0; i < n; i++) {
            int c = target[i] - 'a';
            if (freq[c] > 0) {
                freq[c]--;
                result[i] = target[i];
            } else {
                k = i;
                break;
            }
        }

        int start = min(k, n - 1); // avoid indexing target/result at position n
        for (int idx = start; idx >= 0; idx--) {
            if (idx != k) {
                freq[target[idx] - 'a']++; // undo the earlier match
            }

            int t = target[idx] - 'a';
            int chosen = -1;
            for (int c = t + 1; c < 26; c++) {
                if (freq[c] > 0) { chosen = c; break; }
            }

            if (chosen != -1) {
                freq[chosen]--;
                result[idx] = 'a' + chosen;

                int pos = idx + 1;
                for (int c = 0; c < 26; c++) {
                    while (freq[c] > 0) {
                        result[pos++] = 'a' + c;
                        freq[c]--;
                    }
                }
                return result;
            }
        }

        return "";
    }
};