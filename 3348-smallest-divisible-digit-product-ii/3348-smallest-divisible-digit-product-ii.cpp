class Solution {
public:
    // prime factor counts for each digit 0-9, order: [2,3,5,7]
    const int kFactor[10][4] = {
        {0,0,0,0}, {0,0,0,0}, {1,0,0,0}, {0,1,0,0}, {2,0,0,0},
        {0,0,1,0}, {1,1,0,0}, {0,0,0,1}, {3,0,0,0}, {0,2,0,0}
    };

    bool getPrimeCount(long long t, long long cnt[4]) {
        int primes[4] = {2,3,5,7};
        for (int i = 0; i < 4; i++) {
            cnt[i] = 0;
            while (t % primes[i] == 0) {
                t /= primes[i];
                cnt[i]++;
            }
        }
        return t == 1;
    }

    void getPrimeCountFromString(const string& num, long long cnt[4]) {
        for (int i = 0; i < 4; i++) cnt[i] = 0;
        for (char c : num) {
            int d = c - '0';
            for (int i = 0; i < 4; i++) cnt[i] += kFactor[d][i];
        }
    }

    // returns digit counts (index 2..9) needed to realize prime counts, minimally
    array<long long,10> getFactorCount(long long cnt[4]) {
        array<long long,10> res{};
        long long count2 = cnt[0], count3 = cnt[1], count5 = cnt[2], count7 = cnt[3];

        long long count8 = count2 / 3, rem2 = count2 % 3;
        long long count9 = count3 / 2, rem3 = count3 % 2;
        long long count4 = rem2 / 2, c2 = rem2 % 2;
        long long count6 = 0;

        if (c2 == 1 && rem3 == 1) {
            c2 = 0; rem3 = 0; count6 = 1;
        }
        if (rem3 == 1 && count4 == 1) {
            c2 = 1; count6 = 1; rem3 = 0; count4 = 0;
        }

        res[2] = c2; res[3] = rem3; res[4] = count4; res[5] = count5;
        res[6] = count6; res[7] = count7; res[8] = count8; res[9] = count9;
        return res;
    }

    long long sumValues(const array<long long,10>& f) {
        long long s = 0;
        for (int d = 2; d <= 9; d++) s += f[d];
        return s;
    }

    string construct(const array<long long,10>& f) {
        string res;
        for (int d = 2; d <= 9; d++) res += string(f[d], char('0' + d));
        return res;
    }

    bool isSubset(long long a[4], long long b[4]) {
        for (int i = 0; i < 4; i++) if (a[i] > b[i]) return false;
        return true;
    }

    void subtractInPlace(long long a[4], const long long b[4]) {
        for (int i = 0; i < 4; i++) a[i] = max(0LL, a[i] - b[i]);
    }

    string smallestNumber(string num, long long t) {
        long long primeCount[4];
        if (!getPrimeCount(t, primeCount)) return "-1";

        auto factorCount = getFactorCount(primeCount);
        int n = num.size();
        if (sumValues(factorCount) > n) return construct(factorCount);

        long long primeCountPrefix[4];
        getPrimeCountFromString(num, primeCountPrefix);

        int firstZeroIndex = num.find('0');
        if (firstZeroIndex == (int)string::npos) {
            firstZeroIndex = n;
            if (isSubset(primeCount, primeCountPrefix)) return num;
        }

        for (int i = n - 1; i >= 0; i--) {
            int d = num[i] - '0';
            long long dCnt[4] = {kFactor[d][0], kFactor[d][1], kFactor[d][2], kFactor[d][3]};
            subtractInPlace(primeCountPrefix, dCnt); // now = prefix before i

            int spaceAfter = n - 1 - i;
            if (i > firstZeroIndex) continue;

            for (int biggerDigit = d + 1; biggerDigit <= 9; biggerDigit++) {
                long long remain[4];
                for (int j = 0; j < 4; j++) remain[j] = max(0LL, primeCount[j] - primeCountPrefix[j]);
                long long bdCnt[4] = {kFactor[biggerDigit][0], kFactor[biggerDigit][1],
                                       kFactor[biggerDigit][2], kFactor[biggerDigit][3]};
                subtractInPlace(remain, bdCnt);

                auto factorsAfter = getFactorCount(remain);
                long long need = sumValues(factorsAfter);
                if (need <= spaceAfter) {
                    long long fillOnes = spaceAfter - need;
                    return num.substr(0, i) + char('0' + biggerDigit)
                           + string(fillOnes, '1') + construct(factorsAfter);
                }
            }
        }

        auto factorsAfterExtension = getFactorCount(primeCount);
        long long fillOnes = (long long)(n + 1) - sumValues(factorsAfterExtension);
        return string(fillOnes, '1') + construct(factorsAfterExtension);
    }
};