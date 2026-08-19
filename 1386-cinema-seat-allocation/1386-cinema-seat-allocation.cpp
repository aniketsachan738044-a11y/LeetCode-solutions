class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> rowMask;
        for (auto &r : reservedSeats) {
            int row = r[0], seat = r[1];
            if (seat < 2 || seat > 9) continue; // seat 1,10 irrelevant
            rowMask[row] |= (1 << (seat - 2));
        }

        // rows with no reservations in 2-9: fit 2 families each
        long long count = 2LL * (n - rowMask.size());

        int leftMask  = 0b00001111; // seats 2-5
        int midMask   = 0b00111100; // seats 4-7
        int rightMask = 0b11110000; // seats 6-9

        for (auto &p : rowMask) {
            int mask = p.second;
            if ((mask & leftMask) == 0 && (mask & rightMask) == 0) {
                count += 2; // both left and right blocks free
            } else if ((mask & leftMask) == 0 || (mask & midMask) == 0 || (mask & rightMask) == 0) {
                count += 1; // exactly one block free
            }
        }
        return (int)count;
    }
};