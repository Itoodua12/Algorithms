// Given the root of a binary tree, imagine yourself standing on the right side of it, 
// return the values of the nodes you can see ordered from top to bottom.

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
    void right(TreeNode* root,int level, int &maxLevel, vector<int> &arr){
        if(root==NULL)return;
        if(maxLevel<level){
            arr.push_back(root->val);
            maxLevel = level;
        }
        right(root->right,level+1,maxLevel,arr);
        right(root->left,level+1,maxLevel,arr);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        int  maxLevel = 0;
        int level =1;
        vector<int> arr;
        right(root,level,maxLevel,arr);
        return arr;
    }
};