class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        auto digitSum = [](int x) {
            int s = 0;
            while (x) {
                s += x % 10;
                x /= 10;
            }
            return s;
        };

        // {digitSum, value, original index}
        vector<array<int, 3>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {digitSum(nums[i]), nums[i], i};
        }
        sort(v.begin(), v.end());

        // v[i][2] is the original index of the element that belongs at position i
        vector<bool> vis(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || v[i][2] == i) continue;
            int j = i, cycleLen = 0;
            while (!vis[j]) {
                vis[j] = true;
                j = v[j][2];
                cycleLen++;
            }
            swaps += cycleLen - 1;
        }
        return swaps;
    }
};