class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;
        for (int v : nums) total += v;

        int target = total - x;
        if (target < 0) return -1;   // x is bigger than the whole array sum
        if (target == 0) return n;   // must remove everything

        int left = 0, sum = 0, best = -1;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum > target && left <= right) {
                sum -= nums[left];
                left++;
            }
            if (sum == target) {
                best = max(best, right - left + 1);
            }
        }

        return best == -1 ? -1 : n - best;
    }
};