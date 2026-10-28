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

void postorder(TreeNode* root, vector<int>& ans) {
    if (root==NULL ) return;
        postorder(root->left,ans); // call the left subtree
        postorder(root->right , ans); // call the right subtree
         ans.push_back(root->val); // work for preorder traversal
    }
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};