/**
 * 
 * Given the root of a binary tree, return all root-to-leaf paths in any order.
    A leaf is a node with no children.

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
#include<string>  

class Solution {
public:
    void rec(TreeNode* root, vector<string> &res,string s){
        if(root==NULL) return;
        s +="->"+to_string(root->val);
        
        if(root->left ==NULL && root->right==NULL) {
            res.push_back(s.substr(2));
            return;
        }
        rec(root->left, res, s);
        rec(root->right, res, s);
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string s = "";
        rec(root,res,s);
        return res;
    }
};