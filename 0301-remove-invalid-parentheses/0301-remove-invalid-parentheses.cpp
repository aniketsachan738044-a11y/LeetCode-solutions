class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        // Step 1: find the minimum number of '(' and ')' to remove
        int left = 0, right = 0;
        for (char c : s) {
            if (c == '(') left++;
            else if (c == ')') {
                if (left > 0) left--;
                else right++;
            }
        }

        // Step 2: backtrack, trying to remove exactly `left` '(' and `right` ')'
        unordered_set<string> result;
        string cur;
        dfs(s, 0, left, right, 0, cur, result);
        return vector<string>(result.begin(), result.end());
    }

private:
    void dfs(const string& s, int i, int left, int right, int open,
             string& cur, unordered_set<string>& result) {
        if (i == (int)s.size()) {
            if (left == 0 && right == 0 && open == 0) result.insert(cur);
            return;
        }

        char c = s[i];

        // Option 1: remove this character (only if removals remain)
        if (c == '(' && left > 0)
            dfs(s, i + 1, left - 1, right, open, cur, result);
        else if (c == ')' && right > 0)
            dfs(s, i + 1, left, right - 1, open, cur, result);

        // Option 2: keep this character
        cur.push_back(c);
        if (c == '(') {
            dfs(s, i + 1, left, right, open + 1, cur, result);
        } else if (c == ')') {
            if (open > 0)  // only keep ')' if it has a matching '('
                dfs(s, i + 1, left, right, open - 1, cur, result);
        } else {
            dfs(s, i + 1, left, right, open, cur, result);
        }
        cur.pop_back();
    }
};