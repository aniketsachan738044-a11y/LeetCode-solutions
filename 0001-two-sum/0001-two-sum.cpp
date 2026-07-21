#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = (int)nums.size();
        
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};  // Return immediately on finding the answer
                }
            }
        }
        
        return {};  // Return empty if no answer found (won't happen per problem guarantee)
    }
};