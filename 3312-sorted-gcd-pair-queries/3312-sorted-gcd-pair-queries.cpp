class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = *max_element(nums.begin(), nums.end());
        
        // Step 1: Count frequency of each number in nums
        vector<long long> count(max_val + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        
        // Step 2: Compute number of pairs whose GCD is an exact multiple of i
        vector<long long> gcd_count(max_val + 1, 0);
        for (int i = max_val; i >= 1; --i) {
            long long multiples = 0;
            for (int j = i; j <= max_val; j += i) {
                multiples += count[j];
            }
            
            // Total pairs from these multiples
            long long total_pairs = (multiples * (multiples - 1)) / 2;
            
            // Inclusion-Exclusion: Subtract pairs that have a larger GCD (multiples of i)
            for (int j = 2 * i; j <= max_val; j += i) {
                total_pairs -= gcd_count[j];
            }
            gcd_count[i] = total_pairs;
        }
        
        // Step 3: Build a prefix sum array of the GCD pair counts
        vector<long long> prefix_sums(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            prefix_sums[i] = prefix_sums[i - 1] + gcd_count[i];
        }
        
        // Step 4: Use binary search (upper_bound) to answer each query
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            // Find the first index where prefix_sums[idx] > q
            auto it = upper_bound(prefix_sums.begin(), prefix_sums.end(), q);
            ans.push_back(distance(prefix_sums.begin(), it));
        }
        
        return ans;
    }
};
