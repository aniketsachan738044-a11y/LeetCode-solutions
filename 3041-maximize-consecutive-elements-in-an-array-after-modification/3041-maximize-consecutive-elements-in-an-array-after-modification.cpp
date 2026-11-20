class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(1000003, 0);
        int ans = 1;
        for (int x : nums) {
            dp[x + 1] = dp[x] + 1;   // use x as x+1 (uses old dp[x])
            dp[x] = dp[x - 1] + 1;   // keep x as x
            ans = max(ans, max(dp[x], dp[x + 1]));
        }
        return ans;
    }
};