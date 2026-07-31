class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, curr, res);
        return res;
    }

private:
    void backtrack(vector<int>& candidates, int remain, int start,
                    vector<int>& curr, vector<vector<int>>& res) {
        if (remain == 0) {
            res.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > remain) break; // pruning since sorted
            curr.push_back(candidates[i]);
            backtrack(candidates, remain - candidates[i], i, curr, res); // i, not i+1 (reuse allowed)
            curr.pop_back();
        }
    }
};