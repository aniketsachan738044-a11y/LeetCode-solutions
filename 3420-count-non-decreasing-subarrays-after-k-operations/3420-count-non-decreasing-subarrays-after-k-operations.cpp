class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        vector<int> b(nums.rbegin(), nums.rend());
        int n = b.size();
        deque<int> dq;              // indices, values strictly decreasing
        long long cost = 0, ans = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            // add b[r]: popped segments now have max b[r]
            while (!dq.empty() && b[dq.back()] <= b[r]) {
                int d = dq.back();
                dq.pop_back();
                int prev = dq.empty() ? l - 1 : dq.back();
                cost += (long long)(b[r] - b[d]) * (d - prev);
            }
            dq.push_back(r);
            // shrink from the left while cost exceeds k
            while (cost > k) {
                cost -= b[dq.front()] - b[l];
                if (dq.front() == l) dq.pop_front();
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};