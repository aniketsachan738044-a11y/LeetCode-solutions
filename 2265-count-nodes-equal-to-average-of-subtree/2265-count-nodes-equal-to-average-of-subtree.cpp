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
    int count = 0;

    int dfs(TreeNode* root, long long& sum, int& nodes) {
        if (!root) return 0;

        long long leftSum = 0, rightSum = 0;
        int leftNodes = 0, rightNodes = 0;

        dfs(root->left, leftSum, leftNodes);
        dfs(root->right, rightSum, rightNodes);

        sum = leftSum + rightSum + root->val;
        nodes = leftNodes + rightNodes + 1;

        if (root->val == sum / nodes) count++;

        return 0;
    }

    int averageOfSubtree(TreeNode* root) {
        long long sum = 0;
        int nodes = 0;
        dfs(root, sum, nodes);
        return count;
    }
};