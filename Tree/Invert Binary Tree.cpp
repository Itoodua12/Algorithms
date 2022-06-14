/** 
 * 
    Given the root of a binary tree, invert the tree, and return its root.

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
    void rec(TreeNode* &res){
        if(res==NULL) return;
        TreeNode* temp = res->left;
        res->left = res->right;
        res->right = temp;
        rec(res->left);
        rec(res->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* res = root;
        rec(res);
        return res;

    }
};