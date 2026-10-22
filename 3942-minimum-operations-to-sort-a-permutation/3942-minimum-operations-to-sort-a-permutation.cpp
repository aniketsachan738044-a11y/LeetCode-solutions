class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int k = nums[0];
        const int INF = INT_MAX;
        int ans = INF;

        // Case 1: rotation of ascending order
        bool asc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (k + i) % n) { asc = false; break; }
        }
        if (asc) {
            ans = min(ans, (n - k) % n);
            ans = min(ans, k + 2);
        }

        // Case 2: rotation of descending order
        bool desc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != ((k - i) % n + n) % n) { desc = false; break; }
        }
        if (desc) {
            ans = min(ans, (k + 1) % n + 1);
            ans = min(ans, (n - k - 1) % n + 1);
        }

        return ans == INF ? -1 : ans;
    }
};