/**
 * 
 * Given a binary tree root, a node X in the tree is named good,
 *  if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.
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
    
    int recGoodNodes(TreeNode* root, int max){
        if(!root) return 0;
        int res = 0;
        int val = root->val;
        if(val>=max){
            max = val;
            res =1;
        }
        res+=recGoodNodes(root->left,max);
        res+=recGoodNodes(root->right,max);
        return res;
    }
    
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int val = root->val;
        return 1 + recGoodNodes(root->left,val) + recGoodNodes(root->right,val);
    }
};
