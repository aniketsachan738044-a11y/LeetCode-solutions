class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        // sort indices by value
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        vector<int> result(n);
        int i = 0;
        while (i < n) {
            int j = i;
            // extend the group while consecutive values are within limit
            while (j + 1 < n && nums[idx[j + 1]] - nums[idx[j]] <= limit) j++;

            // positions (original indices) in this group, sorted ascending
            vector<int> positions(idx.begin() + i, idx.begin() + j + 1);
            sort(positions.begin(), positions.end());

            // assign sorted values to sorted positions
            for (int k = 0; k <= j - i; k++) {
                result[positions[k]] = nums[idx[i + k]];
            }
            i = j + 1;
        }
        return result;
    }
};