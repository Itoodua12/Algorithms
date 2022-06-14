/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* solve(vector<int> saver, int left, int right){
        if(left > right) return NULL;
        
        int mid = (left+right)/2;
        TreeNode* newTree = new TreeNode;
        newTree->val = saver[mid];
        newTree->left = solve(saver,left, mid-1);
        newTree->right = solve(saver,mid+1, right);
        
        return newTree;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        
        vector<int> saver;
        
        ListNode* temp = head;
        
        while(temp!=NULL){
            saver.push_back(temp->val);
            temp = temp->next;
        }
        return solve(saver,0,saver.size()-1);
    }
};