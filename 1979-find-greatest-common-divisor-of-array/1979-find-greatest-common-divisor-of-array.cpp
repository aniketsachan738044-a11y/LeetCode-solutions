class Solution {
public:
    int findGCD(std::vector<int>& nums) {
        // Find the minimum and maximum elements in the array
        auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
        
        // Calculate and return the GCD of the smallest and largest values
        return std::gcd(*min_it, *max_it);
    }
};
