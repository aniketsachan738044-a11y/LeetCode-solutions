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

void inorder(TreeNode* root, vector<int>& ans) {
    if (root==NULL ) return;
        inorder(root->left,ans); // call the left subtree
        ans.push_back(root->val); // work for preorder traversal
        inorder(root->right , ans); // call the right subtree
    }
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};