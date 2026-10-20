class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            bool ok = true;
            int prevMax = 0;
            for (int s = 0; s < n && ok; s += k) {
                int desc = 0, mn = INT_MAX, mx = 0;
                for (int j = 0; j < k; j++) {
                    int a = nums[s + j];
                    int b = nums[s + (j + 1) % k];
                    if (a > b) desc++;
                    mn = min(mn, a);
                    mx = max(mx, a);
                }
                // block must be a rotation of its sorted form,
                // and must not go below the previous block's maximum
                if (desc > 1 || mn < prevMax) ok = false;
                prevMax = mx;
            }
            if (ok) ans += k;
        }
        return ans;
    }
};