class Solution {
public:
    int t[101][101];
    int solve(int i,int j,int n,int m,vector<vector<int>>& grid){
        
        if(i<0 ||i>=n ||j<0||j>=m|| grid[i][j]==1 ){
            return 0;
        }
        if(t[i][j]!=-1){
        return t[i][j];
        }
        if(i==n-1 && j==m-1){
            return t[i][j]=1;   
        }
        
        int right=solve(i,j+1,n,m,grid);
        int down=solve(i+1,j,n,m,grid);
        return t[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,n,m,grid);
    }
};