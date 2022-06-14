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
    
    // SPEED -->> LOW (SOLUTION)
    
    void selectAll(TreeNode* root, vector<int> arr,vector<vector<int>> &result){
        if(!root) return;
        if(root->left==NULL && root->right==NULL){
            arr.push_back(root->val);
            result.push_back(arr);
            return;
        }
        
        arr.push_back(root->val);
        selectAll(root->left,arr,result);
        selectAll(root->right,arr,result);
    }
    
    string makeString(vector<int> arr){
        string result="";
        for(int i=arr.size()-1; i>=0;i--){
            int a = arr[i];
            result+=(char)('a'+a);
        }
        return result;
    }
    
    string smallestFromLeaf(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> temp;
        selectAll(root,temp,result);
        vector<string> finally;
        
        for(int i=0; i <result.size();i++){
            vector<int> each = result[i];
            string tempo = makeString(each);
            finally.push_back(tempo);
        }
        string res="z";
        for(int i=0; i <finally.size();i++){
            if(res > finally[i]){
                res = finally[i];
            }
        }
        return res;
    }
};