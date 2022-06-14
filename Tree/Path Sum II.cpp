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
    
   
    void rec( vector<vector<int>> &result,vector<int> temp,TreeNode* root, int targetSum){
        if(!root) return;
        if(root->left == NULL && root->right==NULL && root->val == targetSum){
            temp.push_back(root->val);
            result.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        rec(result,temp,root->left,targetSum-root->val);
        rec(result,temp,root->right,targetSum-root->val);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> temp;
        rec(result,temp,root,targetSum);
        return result;
    }
};