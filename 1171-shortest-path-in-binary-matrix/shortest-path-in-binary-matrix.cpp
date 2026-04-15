class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1){
            return -1;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0] = 1;
        
        int delrow[]={1,1,1,0,0,-1,-1,-1};
        int delcol[]={0,1,-1,-1,1,-1,1,0};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int dis=grid[r][c];
            if(r==n-1 && c==m-1){
                return dis;
            }
            for(int i=0;i<8;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==0){
                q.push({nrow,ncol});
                grid[nrow][ncol]=dis+1;
            }


            }
        }
        return -1;
    }
};