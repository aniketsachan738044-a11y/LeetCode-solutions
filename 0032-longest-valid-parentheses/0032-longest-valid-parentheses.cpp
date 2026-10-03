class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, best = 0;
        int n = s.size();

        // Left to right: handles cases where ')' outnumbers '('
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') left++;
            else right++;

            if (left == right) best = max(best, 2 * right);
            else if (right > left) left = right = 0;
        }

        left = right = 0;

        // Right to left: handles cases where '(' outnumbers ')'
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else right++;

            if (left == right) best = max(best, 2 * left);
            else if (left > right) left = right = 0;
        }

        return best;
    }
};