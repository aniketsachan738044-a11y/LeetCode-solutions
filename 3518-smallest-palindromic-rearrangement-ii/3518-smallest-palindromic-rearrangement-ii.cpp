class Solution {
public:
    string smallestPalindrome(string s, long long k) {
        vector<long long> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        vector<long long> half(26, 0);
        int mid = -1;
        for (int c = 0; c < 26; c++) {
            half[c] = cnt[c] / 2;
            if (cnt[c] % 2) mid = c;
        }
        int halfLen = (int)s.size() / 2;
        const long long CAP = 2000000; // > max k (1e6)

        if (k > countPerm(half, CAP)) return "";

        string halfStr;
        vector<long long> remaining = half;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (remaining[c] == 0) continue;
                remaining[c]--;
                long long ways = countPerm(remaining, CAP);
                if (k <= ways) {
                    halfStr += char('a' + c);
                    break;
                }
                k -= ways;
                remaining[c]++;
            }
        }

        string rev = halfStr;
        reverse(rev.begin(), rev.end());
        string result = halfStr;
        if (mid != -1) result += char('a' + mid);
        result += rev;
        return result;
    }

private:
    // number of distinct permutations of the multiset, capped
    long long countPerm(vector<long long>& c, long long cap) {
        long long result = 1, used = 0;
        for (int ch = 0; ch < 26; ch++) {
            for (long long i = 1; i <= c[ch]; i++) {
                used++;
                result = result * used / i;
                if (result > cap) return cap + 1;
            }
        }
        return result;
    }
};