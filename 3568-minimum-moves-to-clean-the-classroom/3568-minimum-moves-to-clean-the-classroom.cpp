class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = -1, sc = -1;
        vector<vector<int>> litterIdx(m, vector<int>(n, -1));
        int litterCount = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') { sr = i; sc = j; }
                else if (classroom[i][j] == 'L') litterIdx[i][j] = litterCount++;
            }

        if (litterCount == 0) return 0;
        int target = (1 << litterCount) - 1;

        vector<vector<vector<vector<char>>>> visited(
            m, vector<vector<vector<char>>>(
                   n, vector<vector<char>>(
                          energy + 1, vector<char>(1 << litterCount, 0))));

        queue<tuple<int,int,int,int>> q;
        visited[sr][sc][energy][0] = 1;
        q.push({sr, sc, energy, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                auto [r, c, e, mask] = q.front(); q.pop();
                if (mask == target) return dist;
                if (e == 0) continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    char ch = classroom[nr][nc];
                    if (ch == 'X') continue;

                    int ne = (ch == 'R') ? energy : e - 1;

                    int nmask = mask;
                    if (litterIdx[nr][nc] != -1)
                        nmask |= (1 << litterIdx[nr][nc]);

                    if (!visited[nr][nc][ne][nmask]) {
                        visited[nr][nc][ne][nmask] = 1;
                        if (nmask == target) return dist + 1;
                        q.push({nr, nc, ne, nmask});
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};