/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void generateParents(TreeNode*root,TreeNode* parent, unordered_map<TreeNode*,TreeNode*>&map){
        if(!root) return;
        map.insert({root,parent});
        generateParents(root->left,root,map);
        generateParents(root->right,root,map);
    }
    
    bool visited(TreeNode* node,unordered_set<TreeNode*>& vis)
    {
        return vis.find(node)!=vis.end();
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> map;
        unordered_set<TreeNode*> vis;
        generateParents(root,NULL,map);
        
        queue<TreeNode*> q;
        q.push(target);
        vis.insert(target);
        if(k==0) {
            ans.push_back(q.front()->val);
            return ans;
        }
        int level =0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* curNode = q.front();
                q.pop();
                if(curNode->left && !visited(curNode->left,vis)){
                    q.push(curNode->left);
                    vis.insert(curNode->left);
                }
                if(curNode->right && !visited(curNode->right,vis)){
                    q.push(curNode->right);
                    vis.insert(curNode->right);
                }
                 if(map[curNode] && !visited(map[curNode],vis))
                {
                    q.push(map[curNode]);
                    vis.insert(map[curNode]);
                }
            }
             level++;
              if(level==k) break;
               
        }
         int now=q.size();
         while(now--){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};    
