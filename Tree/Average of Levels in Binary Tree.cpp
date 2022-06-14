/**
 *  Given the root of a binary tree, return the average value of the nodes on each level in the form of an array.
  Answers within 10-5 of the actual answer will be accepted.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            int n = size;
            double currSum = 0.0;
            while(size--){
                TreeNode* cur = q.front();
                q.pop();
                currSum+=cur->val;
                if(cur->left !=NULL) q.push(cur->left);
                if(cur->right !=NULL) q.push(cur->right);
            }
            res.push_back(currSum/n);
        }
        return res;
    }
};