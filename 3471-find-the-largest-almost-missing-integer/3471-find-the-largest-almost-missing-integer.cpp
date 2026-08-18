class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Case 1: Subarray size is equal to the entire array size
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Case 2: Subarray size is 1
        if (k == 1) {
            int ans = -1;
            for (auto& [num, count] : freq) {
                if (count == 1) {
                    ans = max(ans, num);
                }
            }
            return ans;
        }

        // Case 3: 1 < k < n
        // Only the extreme first and last elements can appear in exactly one window
        int ans = -1;
        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};
