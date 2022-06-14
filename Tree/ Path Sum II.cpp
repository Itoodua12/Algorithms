/**
 * Given the root of a binary tree and an integer targetSum, 
 * return all root-to-leaf paths where the sum of the node values in the path equals targetSum. 
 * Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node.
 A leaf is a node with no children.
 * 
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
    
    void rec(TreeNode* root, int targetSum, vector<int> temp, vector<vector<int>> &res){
        if(!root) return;
        
        if(root->left ==NULL && root->right==NULL && targetSum ==root->val){
            temp.push_back(root->val);
            res.push_back(temp);
            return;
        }
        
        temp.push_back(root->val);
        rec(root->left,targetSum-root->val,temp,res);
        rec(root->right,targetSum-root->val,temp,res);
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        
        rec(root,targetSum,temp,res);
        return res;
    }
};