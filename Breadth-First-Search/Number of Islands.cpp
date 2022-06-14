/* Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water. */

class Solution {
    public:
        
        bool inside(int i, int j,int height, int width){
            return (i<height && i>=0 && j<width && j>=0);
        }
        
        int numIslands(vector<vector<char>>& grid) {
            
            int h = grid.size();
            int w = grid[0].size();
            int count = 0;
            vector<vector<bool>> vis(h,vector<bool>(w));
            for(int row = 0; row < h; row++){
                for(int col = 0; col <w; col++){
                    if(!vis[row][col] && grid[row][col]=='1'){
                        count++;
                        queue<pair<int,int>> q;
                        q.push({row,col});
                        vis[row][col] = true;
                        while(!q.empty()){
                            pair<int,int> p = q.front();
                            q.pop();
                            
                            if(inside(p.first+1,p.second,h,w) && !vis[p.first+1][p.second] && grid[p.first+1][p.second]=='1'){
                                q.push({p.first+1,p.second});
                                vis[p.first+1][p.second]=true;
                            }
                              if(inside(p.first,p.second+1,h,w) && !vis[p.first][p.second+1] && grid[p.first][p.second+1]=='1'){
                                q.push({p.first,p.second+1});
                                vis[p.first][p.second+1]=true;
                            }
                              if(inside(p.first,p.second-1,h,w) && !vis[p.first][p.second-1] && grid[p.first][p.second-1]=='1'){
                                q.push({p.first,p.second-1});
                                vis[p.first][p.second-1]=true;
                            }
                              if(inside(p.first-1,p.second,h,w) && !vis[p.first-1][p.second] && grid[p.first-1][p.second]=='1'){
                                q.push({p.first-1,p.second});
                                vis[p.first-1][p.second]=true;
                            }
                        }
                    }
                }
            }
            return count;
            
        }
    };