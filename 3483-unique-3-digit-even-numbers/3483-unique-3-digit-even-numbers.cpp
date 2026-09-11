class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> s;
        int n = digits.size();

        for (int i = 0; i < n; ++i) {          // hundreds digit
            if (digits[i] == 0) continue;      // no leading zero
            for (int j = 0; j < n; ++j) {      // tens digit
                if (j == i) continue;
                for (int k = 0; k < n; ++k) {  // units digit
                    if (k == i || k == j) continue;
                    if (digits[k] % 2 != 0) continue; // must be even

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    s.insert(num);
                }
            }
        }

        return s.size();
    }
};