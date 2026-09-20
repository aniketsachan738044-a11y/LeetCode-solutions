class Solution {
public:
    int reverseDegree(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            int reversedPos = 26 - (s[i] - 'a');  // 'a' -> 26, 'z' -> 1
            result += reversedPos * (i + 1);      // multiply by 1-indexed position
        }
        return result;
    }
};