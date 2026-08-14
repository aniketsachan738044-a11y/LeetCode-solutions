class Solution {
public:
    void fillSieve(vector<bool>& sieve){
        int n = sieve.size() - 1;
        for(int i = 2; i <= sqrt(n); i++){
            for(int j = i * i; j <= n; j += i){   // fixed: j<=n, and start from i*i
                sieve[j] = 0;
            }
        }
    }
    
    int countPrimes(int n){
        if(n < 2) return 0;               // handle edge case
        int count = 0;
        vector<bool> sieve(n + 1, 1);
        fillSieve(sieve);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i = 2; i < n; i++){       // countPrimes wants primes < n, not <= n
            if(sieve[i] == 1) count++;
        }
        return count;
    }
};