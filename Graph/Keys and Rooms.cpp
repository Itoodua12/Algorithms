// 
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        queue<int> q;
        set<int> visited;
        
        q.push(0);
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            if(!visited.count(curr)){
                visited.insert(curr);
                
                for(int i=0; i < rooms[curr].size();i++){
                    q.push(rooms[curr][i]);
                }
            }
            if(rooms.size()==visited.size()) return true;
        }
        return false;
        
    }
};