class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n + 1, INT_MAX); // dp[i] = min length of valid subarray within arr[0..i-1]
        int left = 0, sum = 0, ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            dp[right + 1] = dp[right]; // carry forward best length so far

            if (sum == target) {
                int len = right - left + 1;
                dp[right + 1] = min(dp[right + 1], len);

                if (dp[left] != INT_MAX) {
                    ans = min(ans, dp[left] + len);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};