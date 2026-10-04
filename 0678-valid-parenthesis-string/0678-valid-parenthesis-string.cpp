class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;  // min and max possible number of unmatched '('
        for (char c : s) {
            if (c == '(') {
                lo++;
                hi++;
            } else if (c == ')') {
                lo--;
                hi--;
            } else {  // '*' can be '(', ')' or empty
                lo--;
                hi++;
            }
            if (hi < 0) return false;  // too many ')' even if every '*' is '('
            if (lo < 0) lo = 0;        // open count can't be negative
        }
        return lo == 0;
    }
};