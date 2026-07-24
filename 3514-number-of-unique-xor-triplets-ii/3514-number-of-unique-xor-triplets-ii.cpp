class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        std::unordered_set<int> unique_pairs;
        std::unordered_set<int> unique_triplets;
        
        // 1. Precompute and store all unique XOR values of pairs (i, j) where i <= j
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i; j < nums.size(); ++j) {
                unique_pairs.insert(nums[i] ^ nums[j]);
            }
        }
        
        // 2. Compute combinations of (pair_xor) ^ nums[k]
        for (int p_xor : unique_pairs) {
            for (int val : nums) {
                unique_triplets.insert(p_xor ^ val);
            }
        }
        
        return unique_triplets.size();
    }
};
