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
    
    int pathSumFromNode(TreeNode* root, int sum){
        if(!root) return 0;
        
        sum -=root->val;
        int ans= 0;
        if(sum==0) 
            ans =1;
        return ans + pathSumFromNode(root->left,sum)+pathSumFromNode(root->right,sum);
    }
    
    
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        
        return pathSumFromNode(root,targetSum) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
    }
};