class Solution {
public:
    char a[310][310];
    void solve(int i, int j)
    {
        a[i][j]='0';
        if(i>0)
        {
            if(a[i-1][j]=='1') 
                solve(i-1,j);
        }
        if(j>0)
        {
            if(a[i][j-1]=='1')
                solve(i,j-1);
        }
        if(a[i+1][j]=='1')
            solve(i+1,j);
        if(a[i][j+1]=='1')
            solve(i,j+1);

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                a[i][j]=grid[i][j];
            }
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(a[i][j]=='1')
                {
                    cnt++;
                    solve(i,j);
                }
            }
        }
        return cnt;
    }
};