class Solution {
public:
    int countPrimes(int n){
        static vector<char> sieve;
        static int maxN = -1;
        
        if(n < 3) return 0;
        
        if(n - 1 > maxN){
            sieve.assign(n, 1);
            sieve[0] = sieve[1] = 0;
            
            for(int i = 2; (long long)i * i < n; i++){
                if(sieve[i]){
                    for(int j = i * i; j < n; j += i){
                        sieve[j] = 0;
                    }
                }
            }
            maxN = n - 1;
        }
        
        int count = 0;
        for(int i = 0; i < n; i++){
            count += sieve[i];
        }
        return count;
    }
};