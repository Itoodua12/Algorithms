/**
 * Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
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
   
      
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            int max = INT_MIN;
            while(size--){
                TreeNode* cur = q.front();
                q.pop();
                if(max < cur->val) max = cur->val;
                if(cur->left !=NULL) q.push(cur->left);
                if(cur->right !=NULL) q.push(cur->right);
            }
            res.push_back(max);
        }
        return res;
    }
};