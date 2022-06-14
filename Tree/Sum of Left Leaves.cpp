/**
 * Given the root of a binary tree, return the sum of all left leaves.
 * 
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
    void rec(TreeNode* root, int &sum,bool isLeft){
        if(root == NULL) return;
        if(isLeft && (root->left == NULL && root->right == NULL)){
            sum += root->val;
            return;
        }
        rec(root->left,sum,true);
        rec(root->right,sum,false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        rec(root,sum,false);
        return sum;
        
    }
    
    
};