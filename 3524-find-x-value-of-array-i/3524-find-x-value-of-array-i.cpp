class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k, 0), cnt(k, 0);

        for (int a : nums) {
            vector<long long> nxt(k, 0);
            int m = a % k;

            for (int r = 0; r < k; r++) {
                if (cnt[r]) nxt[(r * m) % k] += cnt[r];
            }
            nxt[m]++;  // subarray starting and ending at this element

            for (int r = 0; r < k; r++) res[r] += nxt[r];
            cnt = nxt;
        }
        return res;
    }
};