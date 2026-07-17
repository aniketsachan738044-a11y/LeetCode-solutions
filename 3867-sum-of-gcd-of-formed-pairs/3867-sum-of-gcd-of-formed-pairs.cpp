class Solution {
public:
    long long gcdSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> prefixGcd;
        int maxEl = -1;
        
        // Step 1: Calculate Prefix GCD
        for(int i = 0; i < n; i++) {
            maxEl = std::max(maxEl, nums[i]);
            prefixGcd.push_back(std::gcd(nums[i], maxEl));
        }
        
        // Step 2: Sort the array
        std::sort(prefixGcd.begin(), prefixGcd.end());
        
        // Step 3: Two-pointer pairing to sum GCDs
        long long totalGcd = 0;
        int left = 0;
        int right = n - 1;
        
        while(left < right) {
            totalGcd += std::gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        
        return totalGcd;
    }
};
