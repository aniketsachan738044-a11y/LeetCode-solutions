class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsi(n), psi(n);

        // Next smaller index
        stack<int> st;
        nsi[n-1] = n;
        st.push(n-1);
        for (int i = n-2; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nsi[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Previous smaller index
        stack<int> gt;
        psi[0] = -1;
        gt.push(0);
        for (int i = 1; i < n; i++) {
            while (!gt.empty() && arr[gt.top()] >= arr[i]) gt.pop();
            psi[i] = gt.empty() ? -1 : gt.top();
            gt.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int breadth = nsi[i] - psi[i] - 1;
            maxArea = max(maxArea, arr[i] * breadth);
        }
        return maxArea;
    }
};