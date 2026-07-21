class Solution {
public:
    int maxActiveSectionsAfterTrade(std::string s) {
        int n = s.length();
        int initial_ones = 0;
        
        // Count the original number of '1's in the string
        for (char c : s) {
            if (c == '1') {
                initial_ones++;
            }
        }
        
        // Group consecutive identical characters into segments: {character, length}
        std::vector<std::pair<char, int>> groups;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            groups.push_back({s[i], j - i});
            i = j;
        }
        
        int max_zeros_gained = 0;
        bool trade_possible = false;
        
        // Iterate through the blocks to find valid trades
        for (int idx = 0; idx < groups.size(); ++idx) {
            if (groups[idx].first == '1') {
                // Check if this '1' block is surrounded by '0's in the augmented string t = '1' + s + '1'
                // An inner '1' block is surrounded by '0's if it has '0' groups on both sides.
                bool left_has_zero = (idx > 0 && groups[idx - 1].first == '0');
                bool right_has_zero = (idx + 1 < groups.size() && groups[idx + 1].first == '0');
                
                if (left_has_zero && right_has_zero) {
                    trade_possible = true;
                    int left_zeros = groups[idx - 1].second;
                    int right_zeros = groups[idx + 1].second;
                    
                    // A valid trade merges the left and right zero groups
                    max_zeros_gained = std::max(max_zeros_gained, left_zeros + right_zeros);
                }
            }
        }
        
        // If a valid block of '1's was found and traded, add the best zero merge gain
        if (trade_possible) {
            return initial_ones + max_zeros_gained;
        }
        
        // If no trade can be legally initiated, return the baseline count
        return initial_ones;
    }
};
