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
    
    void buildIt(TreeNode* root, vector<int> arr){
        TreeNode* curr = root;
        root->left = NULL;
        root->right =NULL;
        for(int i=1; i < arr.size();i++){
            TreeNode* temp = new TreeNode;
            temp->val =arr[i];
            curr->right = temp;
            curr = curr->right;
        }
    }
    
    void inOrderTravelsal(TreeNode*root,vector<int>& arr){
        if(!root) return;
        arr.push_back(root->val);
        inOrderTravelsal(root->left,arr);
        inOrderTravelsal(root->right,arr);
    }
    
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<int> arr;
        inOrderTravelsal(root,arr);
        buildIt(root,arr);
    }
};