class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> dq; // stores indices, values in decreasing order
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            // remove indices that are out of this window's range
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // remove smaller elements from back — they can never be the max
            // while a larger/equal element exists to their right
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // front of deque is always the max of current window
            if (i >= k - 1) {
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
};