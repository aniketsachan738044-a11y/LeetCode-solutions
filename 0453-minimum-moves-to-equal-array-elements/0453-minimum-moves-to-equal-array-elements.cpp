class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        int mn = nums[0];
        
        for (int x : nums) {
            sum += x;
            mn = min(mn, x);
        }
        
        return (int)(sum - (long long)n * mn);
    }
};