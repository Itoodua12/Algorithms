// There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

// You want to determine if there is a valid path that exists from vertex start to vertex end.

// Given edges and the integers n, start, and end, return true if there is a valid path from start to end, or false otherwise.

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> eachPath(n);
        queue<int> q;
        set<int> seen;
        for(int i=0; i <edges.size();i++){
            int from = edges[i][0];
            int to = edges[i][1];
            eachPath[from].push_back(to);
            eachPath[to].push_back(from);
        }
        q.push(start);
        seen.insert(start);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i=0; i <eachPath[curr].size();i++){
                int second = eachPath[curr][i];
                if(!seen.count(second)){
                    q.push(second);
                    seen.insert(second);
                }
            }
        }
        if(seen.count(end)) return true;
        return false;
    }
};