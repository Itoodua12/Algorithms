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
    
    void rec(TreeNode* root, int targetSum, bool &check){
        if(!root) return;
        if(root->left==NULL && root->right==NULL){
            if(targetSum-root->val ==0){
                check=true;
                return;
            }
        }
        rec(root->left,targetSum-(root->val),check);
        rec(root->right,targetSum-(root->val),check);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool check = false;
        rec(root,targetSum,check);
        return check;
    }
    
    
    
};