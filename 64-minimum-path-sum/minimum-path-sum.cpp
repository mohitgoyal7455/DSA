class Solution {
public:
    int t[201][201];
    int solve(int i,int j,int n,int m,vector<vector<int>>& grid){
        if(i<0||i>n||j<0 ||j>m){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(i==n-1 && j==m-1){
            return t[i][j]=grid[i][j];
        }
        else if(i==n-1){
            return t[i][j]=grid[i][j]+solve(i,j+1,n,m,grid);
        }
        else if(j==m-1){
            return t[i][j]=grid[i][j]+solve(i+1,j,n,m,grid);
        }
        else{
            return t[i][j]=grid[i][j]+min(solve(i,j+1,n,m,grid),solve(i+1,j,n,m,grid));
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,n,m,grid);
        

        
    }
};