class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;

                long long sum = 0;
                vector<pair<int,int>> st;
                st.push_back({i, j});
                sum += grid[i][j];
                grid[i][j] = 0; // mark visited

                while (!st.empty()) {
                    auto [x, y] = st.back();
                    st.pop_back();
                    for (auto& d : dirs) {
                        int nx = x + d[0], ny = y + d[1];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0) {
                            sum += grid[nx][ny];
                            grid[nx][ny] = 0;
                            st.push_back({nx, ny});
                        }
                    }
                }

                if (sum % k == 0) count++;
            }
        }
        return count;
    }
};