class Solution {
public:
    int n,m;
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& board){
        vis[i][j]=1;
        vector<int>delrow={-1,0,1,0}; 
        vector<int>delcol={0,1,0,-1};
        for(int row=0;row<4;row++){
            int nrow=i+delrow[row];
            int ncol=j+delcol[row];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol <m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m));

        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O' ){
                dfs(0,j,vis,board);

            }
            if(!vis[n-1][j] && board[n-1][j]=='O' ){
                dfs(n-1,j,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O' ){
                dfs(i,0,vis,board);

            }
            if(!vis[i][m-1] && board[i][m-1]=='O' ){
                dfs(i,m-1,vis,board);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};