/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int numbersoflevels(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(numbersoflevels(root->left), numbersoflevels(root->right));
    }

    void nthlevel(TreeNode* root, int curr, int level, vector<int>& v) {
        if (root == nullptr) return;
        if (curr == level) {
            v.push_back(root->val);
            return;
        }
        nthlevel(root->left, curr + 1, level, v);
        nthlevel(root->right, curr + 1, level, v);
    }

    void lorder(TreeNode* root, vector<vector<int>>& ans) {
        int n = numbersoflevels(root);
        for (int i = 1; i <= n; i++) {
            vector<int> v;
            nthlevel(root, 1, i, v);
            ans.push_back(v);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        lorder(root, ans);
        return ans;
    }
};