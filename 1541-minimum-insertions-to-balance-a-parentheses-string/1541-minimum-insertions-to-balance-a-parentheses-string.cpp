class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;   // insertions made so far
        int open = 0;  // unmatched '(' so far
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            } else {
                // Try to form "))" from the current and next character
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;        // consume the pair
                } else {
                    ans++;      // insert one ')' to complete the pair
                }

                if (open > 0) {
                    open--;     // match with a previous '('
                } else {
                    ans++;      // insert a '(' to match this "))"
                }
            }
        }

        // Each leftover '(' needs two ')'
        return ans + open * 2;
    }
};