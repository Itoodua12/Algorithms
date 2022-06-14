/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    int maxDepth(Node* root) {
        int res = 0;
        if(!root) return 0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node* temp = q.front();
                q.pop();
                for(int i=0; i < temp->children.size();i++){
                    q.push(temp->children[i]);
                }
            }
            res++;
        }
        return res;
        
    }
};


