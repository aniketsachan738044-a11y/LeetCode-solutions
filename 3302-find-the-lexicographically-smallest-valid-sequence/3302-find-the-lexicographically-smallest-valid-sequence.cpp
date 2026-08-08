class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        // lastMatch[j] = rightmost-anchored index in word1 that allows
        // word2[j:] to be matched exactly (0 mismatches) as a subsequence.
        vector<int> lastMatch(m, -1);
        for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; --i) {
            if (word1[i] == word2[j]) {
                lastMatch[j] = i;
                --j;
            }
        }

        vector<int> result;
        int mismatchUsed = 0;

        for (int i = 0; i < n && result.size() < m; ++i) {
            int j = result.size();
            bool exact = (word1[i] == word2[j]);
            bool canMismatch = (mismatchUsed == 0) &&
                                (j + 1 == m || i < lastMatch[j + 1]);

            if (exact || canMismatch) {
                if (!exact) ++mismatchUsed;
                result.push_back(i);
            }
        }

        if (result.size() != m) return {};
        return result;
    }
};
