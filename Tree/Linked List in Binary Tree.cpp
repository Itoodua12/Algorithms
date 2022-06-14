/**
 * Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.
 * 
 * 
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
    
    bool bfs(ListNode* head, TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        ListNode* curr = head->next;
        while(!q.empty() && curr !=NULL){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left !=NULL && node->left->val == curr->val){
                    q.push(node->left);
                }
                if(node->right !=NULL && node->right->val == curr->val){
                    q.push(node->right);
                }
            }
            if(!q.empty()) curr = curr->next;
        }
        return curr == NULL;
    }
    
    
    bool dfs(ListNode* head, TreeNode* root){
        if(!root) return false;
        if(head->val == root->val && bfs(head,root)) return true;
        return dfs(head,root->left) || dfs(head,root->right);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head,root);
    }
};