class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int odd = 0, even = 1; // even = 1 counts the empty prefix (sum 0)
        int parity = 0;

        for (int x : arr) {
            parity = (parity + x) % 2;
            if (parity == 1) {
                ans += even;  // odd prefix - even prefix = odd subarray
                odd++;
            } else {
                ans += odd;   // even prefix - odd prefix = odd subarray
                even++;
            }
            ans %= MOD;
        }
        return ans;
    }
};