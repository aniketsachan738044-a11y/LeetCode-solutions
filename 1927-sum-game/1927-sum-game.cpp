class Solution {
public:
    bool sumGame(string s) {
        int n = s.size(), half = n / 2;
        long long leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < half; i++) {
            if (s[i] == '?') leftQ++;
            else leftSum += s[i] - '0';
        }
        for (int i = half; i < n; i++) {
            if (s[i] == '?') rightQ++;
            else rightSum += s[i] - '0';
        }

        int totalQ = leftQ + rightQ;
        if (totalQ % 2 != 0) return true;  // odd '?' count -> Alice always wins

        long long diff = leftSum - rightSum;
        if (diff == 0) return leftQ != rightQ;

        if (diff > 0) {
            if (leftQ >= rightQ) return true;
            if (diff < 9) return true;
            long long maxCatchUp = (long long)(rightQ - leftQ) / 2 * 9;
            return maxCatchUp != diff;
        } else {
            if (leftQ <= rightQ) return true;
            if (diff > -9) return true;
            long long maxCatchUp = (long long)(leftQ - rightQ) / 2 * 9;
            return maxCatchUp != -diff;
        }
    }
};
