/*
	https://leetcode.com/problems/invert-binary-tree/
*/
class Solution{
public:
    TreeNode* invertTree(TreeNode* root){
        if(root==NULL)
            return root;
        root->left=invertTree(root->left);
        root->right=invertTree(root->right);
        TreeNode *tmp=root->left;
        root->left=root->right;
        root->right=tmp;
        return root;
    }
};
