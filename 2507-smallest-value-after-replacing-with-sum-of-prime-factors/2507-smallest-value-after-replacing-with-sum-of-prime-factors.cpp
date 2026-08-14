class Solution {
public:
    int smallestValue(int n) {
        while (true) {
            int sum = 0, temp = n;
            for (int i = 2; i <= temp / i; i++) {
                while (temp % i == 0) {
                    sum += i;
                    temp /= i;
                }
            }
            if (temp > 1) sum += temp;   // leftover large prime factor
            if (sum == n) return n;       // n was prime (sum of its own factorization equals itself)
            n = sum;
        }
    }
};