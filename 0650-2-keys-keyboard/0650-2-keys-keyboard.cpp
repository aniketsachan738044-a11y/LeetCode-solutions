class Solution {
public:
    // Helper function to check if a number is prime
    bool isPrime(int n) {
        if (n <= 1) return false;
        // Check divisibility up to sqrt(n) efficiently
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    // Helper function to find the Greatest Proper Divisor (gd)
    int gd(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return n / i; 
        }
        return 1;
    }

    // Main LeetCode function
    int minSteps(int n) {
        int count = 0;
        while (n > 1) {
            if (isPrime(n)) {
                count += n;
                break;
            }
            int hf = gd(n);
            count += (n / hf); // Step cost (smallest prime factor)
            n = hf;            // Reduce n to its greatest proper divisor
        }
        return count;
    }
};