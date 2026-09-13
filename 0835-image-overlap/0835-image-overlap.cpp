class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> ones1, ones2;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) ones1.push_back({i, j});
                if (img2[i][j] == 1) ones2.push_back({i, j});
            }

        unordered_map<int, int> count;
        int maxOverlap = 0;

        for (auto& a : ones1) {
            for (auto& b : ones2) {
                int dx = a.first - b.first;
                int dy = a.second - b.second;
                int key = (dx + n) * 100 + (dy + n); // n <= 30, so this stays unique
                count[key]++;
                maxOverlap = max(maxOverlap, count[key]);
            }
        }

        return maxOverlap;
    }
};