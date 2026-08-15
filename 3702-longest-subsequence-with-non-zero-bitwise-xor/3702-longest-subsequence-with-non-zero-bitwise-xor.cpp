class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        bool hasNonZero = false;

        for (int n : nums) {
            x ^= n;
            if (n != 0) hasNonZero = true;
        }

        if (!hasNonZero) return 0;      // all zeros
        if (x != 0) return nums.size(); // whole array works
        return nums.size() - 1;         // drop one non-zero element
    }
};