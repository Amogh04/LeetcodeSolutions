class Solution {
public:
    vector<int> dx = {-1,1,0,0}, dy = {0,0,-1,1};
    int mx(int a, int b){
        return a>b ? a : b;
    }
    void BFS(vector<vector<int>>& grid, map<pair<int,int>,int>& vis, queue<pair<int,int>>& q){
        while(!q.empty()){
            int y = q.front().first, x = q.front().second;
            q.pop();
            for(int i=0;i<4;++i){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx<0 || ny<0 || nx>=grid[0].size() || ny>=grid.size() || grid[ny][nx]==0)
                    continue;
                if(grid[y][x]==-1 && !vis[{ny,nx}]){
                    grid[ny][nx] = -1;
                    q.push({ny,nx});
                    vis[{ny,nx}]=1;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
         map<pair<int,int>,int>vis;
         queue<pair<int,int>>q;
         for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(grid[i][j]==1){
                    if(i%mx(1,grid.size()-1)==0 || j%mx(1,grid[0].size()-1)==0){
                        grid[i][j] = -1;
                        q.push({i,j});
                        vis[{i,j}]=1;
                    }
                }
            }
         }
         BFS(grid,vis,q);
         int land = 0;
         for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==1)   land++;
            }
         }
         return land;  
    }
};


/*

Intuition
Using BFS

Approach
---> We will represent movable land by -1
---> So the land on edges and land which is adjacent to that land will be marked -1
---> The land on edges is marked -1 in the for loop inside main().
---> Using BFS, we traverse all that land which is connected to -1 marked land and push it in the queue and continue like that.

Time complexity:
O(M*N)
	
*/