/**
 * 
    You are given the root of a binary tree containing digits from 0 to 9 only.

    Each root-to-leaf path in the tree represents a number.

    For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
    Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

    A leaf node is a node with no children.
    
 *
 *  Definition for a binary tree node.
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
    
    void rec(TreeNode* root, int sum, vector<int> &temp){
        if(!root) return;
        if(root->left ==NULL && root->right==NULL){
            sum = (sum*10 + root->val);
            temp.push_back(sum);
            return;
        }
        
        sum = (sum*10 + root->val);
        rec(root->left,sum,temp);
        rec(root->right,sum,temp);
    }
    
    
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        vector<int> temp;
        rec(root,sum,temp);
        int result =0;
        for(int i=0; i < temp.size();i++){
            result+=temp[i];
        }
        return result;
    }
};