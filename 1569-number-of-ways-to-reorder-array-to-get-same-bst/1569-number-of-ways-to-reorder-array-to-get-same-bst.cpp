class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<vector<long long>> C;

    long long solve(vector<int>& arr) {
        int m = arr.size();
        if (m <= 2) return 1;

        vector<int> left, right;
        for (int i = 1; i < m; i++) {
            if (arr[i] < arr[0]) left.push_back(arr[i]);
            else right.push_back(arr[i]);
        }

        long long res = C[m - 1][left.size()];
        res = res * solve(left) % MOD;
        res = res * solve(right) % MOD;
        return res;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        C.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++)
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
        return (solve(nums) - 1 + MOD) % MOD;
    }
};