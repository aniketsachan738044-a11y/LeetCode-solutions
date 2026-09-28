class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, maxD = 0;
        for (char c : s) {
            if (c == '(') {
                depth++;
                maxD = max(maxD, depth);
            } else if (c == ')') {
                depth--;
            }
        }
        return maxD;
    }
};