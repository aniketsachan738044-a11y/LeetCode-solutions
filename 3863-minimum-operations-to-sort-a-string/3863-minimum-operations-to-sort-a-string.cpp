class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (is_sorted(s.begin(), s.end())) return 0;
        if (n == 2) return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // sort suffix s[1..] or prefix s[0..n-2]
        if (s[0] == mn || s[n - 1] == mx) return 1;

        // s[0] is the unique max and s[n-1] is the unique min
        bool uniqueMaxFront = (s[0] == mx) && count(s.begin(), s.end(), mx) == 1;
        bool uniqueMinBack  = (s[n - 1] == mn) && count(s.begin(), s.end(), mn) == 1;
        if (uniqueMaxFront && uniqueMinBack) return 3;

        return 2;
    }
};