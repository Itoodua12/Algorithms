/**
 * 
 * Given the root of a binary tree, return the leftmost value in the last row of the tree.


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
    
    void rec(TreeNode* root,int now ,int &max, int &value){
        if(!root) return;
        if(root->left==NULL && root->right==NULL){
            if(now > max){
                max = now;
                value =root->val;
                return;
            }
        }
        rec(root->left,now+1,max,value);
        rec(root->right,now+1,max,value);
    }
    
    
    int findBottomLeftValue(TreeNode* root) {
        int now = 1;
        int max = 0;
        int value = 0;
        rec(root,now,max,value);
        return value;
    }
};