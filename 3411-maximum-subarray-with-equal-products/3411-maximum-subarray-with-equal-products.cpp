class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            long long prod = 1, g = 0, l = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);
                if (prod > 100000) break;   // lcm * gcd can never exceed this
                if (prod == l * g) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};