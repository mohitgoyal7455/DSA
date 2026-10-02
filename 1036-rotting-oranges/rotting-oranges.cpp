class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }   
        int time=0;
        vector<int>delrow={-1,0,1,0};
        vector<int>delcol={0,1,0,-1};     
        while(!q.empty() && fresh>0){
            int s=q.size();
            for(int i=0;i<s;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();

                for(int j=0;j<4;j++){
                    int nrow=r+delrow[j];
                    int ncol=c+delcol[j];
                    if(nrow>=0 && nrow<n && ncol >=0 && ncol <m && grid[nrow][ncol]==1 ){
                        grid[nrow][ncol]=2;
                        fresh--;
                        q.push({nrow,ncol});

                    }
                }
            }
            time++;
        }
        if(fresh>0){
            return -1;
        }
        return time;

    }

};