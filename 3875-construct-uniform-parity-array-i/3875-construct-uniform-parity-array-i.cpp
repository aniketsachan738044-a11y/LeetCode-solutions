class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int countOdd = 0;
        for (int x : nums1) {
            if (x & 1) countOdd++;
        }
        bool evenAchievable = (countOdd != 1);
        bool oddAchievable = (countOdd > 0);
        return evenAchievable || oddAchievable;
    }
};