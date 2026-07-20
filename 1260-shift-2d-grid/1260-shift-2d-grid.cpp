

class Solution {
public:
    std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int totalElements = m * n;
        
        // Optimize k to avoid redundant full rotations
        k = k % totalElements;
        
        // Initialize an empty grid of the same dimensions
        std::vector<std::vector<int>> result(m, std::vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 1. Convert 2D index (i, j) to a 1D linear index
                int current1DIndex = i * n + j;
                
                // 2. Apply shift and wrap around using modulo
                int new1DIndex = (current1DIndex + k) % totalElements;
                
                // 3. Convert the new 1D index back to 2D coordinates
                int newRow = new1DIndex / n;
                int newCol = new1DIndex % n;
                
                // Assign value to the shifted position
                result[newRow][newCol] = grid[i][j];
            }
        }
        
        return result;
    }
};
