class Solution {
public:
    int countPrimes(int n){
        if(n < 3) return 0;
        vector<char> sieve(n, 1);   // char instead of bool — faster access
        sieve[0] = sieve[1] = 0;
        
        for(int i = 2; (long long)i * i < n; i++){
            if(sieve[i]){
                for(int j = i * i; j < n; j += i){
                    sieve[j] = 0;
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i < n; i++){
            count += sieve[i];
        }
        return count;
    }
};