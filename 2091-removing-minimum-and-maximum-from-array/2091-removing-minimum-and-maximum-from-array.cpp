class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        
        int lo = min(minIdx, maxIdx);
        int hi = max(minIdx, maxIdx);
        
        // Option 1: remove both from the front
        int fromFront = hi + 1;
        // Option 2: remove both from the back
        int fromBack = n - lo;
        // Option 3: remove one from front, one from back
        int mixed = (lo + 1) + (n - hi);
        
        return min({fromFront, fromBack, mixed});
    }
};