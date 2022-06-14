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
    TreeNode* rec(vector<int> &nums,int first, int end){
        if(first > end) return NULL;
        
        int middle = (first+end)/2;
        TreeNode * root = new TreeNode;
        root->val = nums[middle];
        root->left = rec(nums,first,middle-1);
        root->right = rec(nums,middle+1,end);
        return root;
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int first = 0;
        int end = nums.size()-1;
        TreeNode* res = rec(nums,first,end);
        return res;
    }
};

