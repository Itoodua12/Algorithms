
// !!! -> Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values.
//  (i.e., from left to right, level by level from leaf to root).

struct TreeNode {
    int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size--){
                TreeNode* tmp = q.front();
                q.pop();
                temp.push_back(tmp->val);
                if(tmp->left !=NULL) q.push(tmp->left);
                if(tmp->right !=NULL) q.push(tmp->right);
            }
            res.insert(res.begin(),temp);
        }
        return res;
    }
};