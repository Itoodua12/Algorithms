/**
    !!! Given the root of a binary tree, return its maximum depth.

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

struct TreeNode {
    int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    void rec(TreeNode* root, int &depth, int now){
        if(!root){
            if(now> depth) depth = now;
            return;
        }
        rec(root->left,depth,now+1);
        rec(root->right,depth,now+1);

    }
    
    
    int maxDepth(TreeNode* root) {
        int depth = 0;
        int now = 0;
        rec(root,depth,now);
        return depth;
    }
};