class Solution {
public:
    static const int MOD = 1e9 + 7;
    
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    
    int numberOfSets(int n, int k) {
        // This problem reduces to a combinatorics identity:
        // answer = C(n + k - 1, 2k) mod (1e9+7)
        
        int top = n + k - 1;
        int bottom = 2 * k;
        
        if (bottom > top) return 0;
        
        // Compute C(top, bottom) mod MOD using factorials
        vector<long long> fact(top + 1);
        fact[0] = 1;
        for (int i = 1; i <= top; i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }
        
        long long numerator = fact[top];
        long long denom = (fact[bottom] * fact[top - bottom]) % MOD;
        long long invDenom = power(denom, MOD - 2, MOD);
        
        return (int)((numerator * invDenom) % MOD);
    }
};