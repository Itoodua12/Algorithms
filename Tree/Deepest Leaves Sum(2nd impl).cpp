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
    void rec(TreeNode* root, int &result, int &maxHeight,int now){
        if(root==NULL) return;
        if(root->left ==NULL && root->right == NULL && now == maxHeight)
            result+=root->val;
        
        rec(root->left,result,maxHeight,now+1);
        rec(root->right,result,maxHeight,now+1);
        
    }
    
    int height(TreeNode* root){
        if(!root) return 0;
        
        int h1 = height(root->left);
        int h2 = height(root->right);
        return 1 + max(h1,h2);
    }
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;
        int maxHeight = height(root);
        int now = 1;
        rec(root,res,maxHeight,now);
        return res;
    }
};