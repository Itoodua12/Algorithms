
// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int components = 0;
        queue<int> q;
        set<int> set;
        
        for(int i=0; i < isConnected.size();i++){
            if(!set.count(i)){
                set.insert(i);
                q.push(i);
                
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    for(int j =0; j <isConnected.size();j++){
                        if(isConnected[curr][j]==1 && !set.count(j)){
                            set.insert(j);
                            q.push(j);  
                        }
                    }
                }
                components++;
            }
        }
        return components;
        
        
    }
};