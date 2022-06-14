// Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: 
// “The lowest common ancestor is defined between
//  two nodes p and q as the lowest node in T that has both p and q as descendants
//   (where we allow a node to be a descendant of itself).”

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* lca(TreeNode* root, int first, int second){
        if(!root) return NULL;
        
        if(root->val > first && root->val > second){
            return lca(root->left,first,second);
        }
        if(root->val < first && root->val < second){
            return lca(root->right,first,second);
        }
        return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int first = p->val;
        int second = q->val;
        TreeNode* result = lca(root,first,second);
        return result;
    }
};