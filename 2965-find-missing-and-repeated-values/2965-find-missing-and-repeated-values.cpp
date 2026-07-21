class Solution {
public:
    std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
        std::vector<int> ans;
        std::unordered_set<int> s;
        int n = grid.size();
        int a = -1, b = -1;
        long long actualSum = 0;
        long long totalElements = (long long)n * n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                actualSum += val;
                
                // Check if the number is already in the set (it's the repeated value)
                if (s.find(val) != s.end()) {
                    a = val; 
                }
                s.insert(val);
            }
        }

        // Formula: n * (n + 1) / 2 where n is the total number of elements
        long long expSum = totalElements * (totalElements + 1) / 2;
        
        // Missing value = Expected Sum - Actual Sum + Repeated Value
        b = expSum + a - actualSum;

        ans.push_back(a);
        ans.push_back(b);

        return ans;
    }
};
