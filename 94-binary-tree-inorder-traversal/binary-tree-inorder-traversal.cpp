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

 void Traversal(vector<int> &v,TreeNode* root)
 {
    if(root == NULL)
        return ;
    Traversal(v,root->left);
    v.push_back(root->val);
    Traversal(v,root->right);
 }
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)
        return {} ;
        vector<int> v;
        Traversal(v,root);
        return v;

    }
};