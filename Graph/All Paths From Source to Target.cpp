// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

// The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> result;
        vector<int> path;
        
        findAllPath(graph,result,path,0, graph.size()-1);
        return result;
    }
    
    
    void findAllPath(vector<vector<int>>& graph,vector<vector<int>> &result,vector<int> path,int source,int target){
        if(source==target){
            path.push_back(source);
            result.push_back(path);
            return;
        }
        
        
        path.push_back(source);
        for(int i=0; i < graph[source].size();i++){
            findAllPath(graph,result,path,graph[source][i],target);
        }
    }
};