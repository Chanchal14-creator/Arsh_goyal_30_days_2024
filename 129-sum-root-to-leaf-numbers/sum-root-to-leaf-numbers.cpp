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
    void dfs(TreeNode* root,int &ans,int k)
    {
        if(root==NULL)
        return;
        k=k*10+root->val;
         if(root->left==NULL&&root->right==NULL)
         {ans+=k;
         return;
         }
        dfs(root->left,ans,k);
        dfs(root->right,ans,k);
        return;
    }

    int sumNumbers(TreeNode* root) {
        int ans=0;
        int k=0;
        dfs(root,ans,k);
        return ans;
    }
};