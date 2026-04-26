class Solution {
public:
    bool dfs(int i, int j,vector<vector<int>>& vis,int n,int m,vector<vector<char>>& grid,int x,int y){
        vis[i][j] = 1;
        int nrow[] = {1,0,-1,0};
        int ncol[] = {0,-1,0,1};
        for(int k =0; k<4; k++){
            int r = i+nrow[k];
            int c = j+ncol[k];
            if(r >= 0 && r <n && c >= 0 && c < m && grid[r][c] == grid[i][j]){
                if(r == x && c == y) continue;
                if(vis[r][c]) return true;
                else{
                    if (dfs(r, c, vis, n, m, grid, i, j)) return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(!vis[i][j]){
                    if(dfs(i,j,vis,n,m,grid,-1,-1)) return true;
                }       
            }
        }
        return false;
    }
};