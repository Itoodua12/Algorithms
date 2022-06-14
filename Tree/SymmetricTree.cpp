// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

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
    
    bool isMirror(TreeNode* r, TreeNode* p){
        if(r==NULL && p==NULL) return true;
        if(r==NULL || p==NULL) return false;
        if(r->val==p->val && isMirror(r->left,p->right) && isMirror(r->right,p->left)) return true;
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
    }
};