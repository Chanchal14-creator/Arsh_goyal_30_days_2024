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
    void dfs(int depth, TreeNode*root, int val)
    {
        if(root==NULL)
        return;
        if(depth==2){
        TreeNode* swp;
        swp=root->left;
        TreeNode* newnodel= new TreeNode(val,swp,NULL);
        root->left=newnodel;
        swp=root->right;
        TreeNode* newnoder= new TreeNode(val,NULL,swp);
        root->right=newnoder;
        return;
        }
        
        depth--;
        dfs(depth,root->left,val);
        dfs(depth,root->right,val);




        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<int>q;
        if(depth==1)
        {
            TreeNode *node=new TreeNode(val,root,NULL);
            return node;
        }
        dfs(depth,root,val);
        return root;
    }
};