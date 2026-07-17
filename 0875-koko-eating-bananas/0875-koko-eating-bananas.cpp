class Solution {
public:
    bool check(int speed, vector<int>& piles, int h){
        long long count = 0; // Fixed: Changed to long long to prevent overflow
        int n = piles.size();
        
        for(int i = 0; i < n; i++){
            // Simplified math: ceiling division (piles[i] + speed - 1) / speed
            count += (piles[i] + speed - 1) / speed; 
            
            if(count > h) return false; // Early exit optimization
        }
        
        return true; // Fixed: Returns true if count <= h
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int mx = -1;
        for(int i = 0; i < n; i++){
            mx = max(mx, piles[i]);
        }
        
        int lo = 1;
        int hi = mx;
        int ans = -1;
        
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(check(mid, piles, h) == true){
                ans = mid;
                hi = mid - 1; // Try to find a smaller valid speed
            }
            else {
                lo = mid + 1; // Speed is too slow, increase it
            }
        }
        return ans;
    }
};
