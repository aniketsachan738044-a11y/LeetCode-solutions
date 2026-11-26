class Solution {
public:
    bool canAliceWin(int n) {
        int k = 10;
        int turns = 0;
        while (k > 0 && n >= k) {
            n -= k;
            k--;
            turns++;
        }
        // Alice moves on odd-numbered turns (1st, 3rd, ...).
        // If the last successful move was hers, Bob can't move and Alice wins.
        return turns % 2 == 1;
    }
};